import os

from cs50 import SQL
from datetime import datetime
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Default route
@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # get portfolio info
    portfolio_info = db.execute(
        "SELECT * FROM portfolio WHERE uid = ?", session["user_id"]
    )
    for row in portfolio_info:
        row["price"] = lookup(row["symbol"])["price"]
        row["value"] = row["price"] * row["share"]

    # calculate cash balance
    cash_balance = db.execute(
        "SELECT cash FROM users WHERE id = ?", session["user_id"]
    )[0]["cash"]

    # calculate account value
    account_value = cash_balance
    for row in portfolio_info:
        account_value += row["value"]

    # turn relavant values into USD
    for row in portfolio_info:
        row["price"] = usd(row["price"])
        row["value"] = usd(row["value"])
    account_value = usd(account_value)
    cash_balance = usd(cash_balance)

    # render index
    return render_template(
        "index.html",
        portfolio_info=portfolio_info,
        account_value=account_value,
        cash_balance=cash_balance,
    )


# Buy
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # Process purchase request
    if request.method == "POST":
        # validate share
        if request.form.get("shares").isdigit() == False:
            return apology("Invalid shares")
        share = int(request.form.get("shares"))
        if share <= 0:
            return apology("Invalid shares")

        # validate symbol
        result = lookup(request.form.get("symbol"))
        if result == None:
            return apology("Invalid symbol")

        # validate cost
        cost = share * result["price"]
        usr_balance = db.execute(
            "SELECT cash FROM users WHERE id = ?", session["user_id"]
        )[0]["cash"]
        if cost > usr_balance:
            return apology("Not enough money")

        # pass all checks, process purchase
        else:
            # log purchase history
            db.execute(
                "INSERT INTO history (uid, symbol, share, price, time) VALUES(?, ?, ?, ?, ?)",
                session["user_id"],
                result["symbol"],
                share,
                result["price"],
                datetime.now(),
            )

            # log portfolio
            # current holding list
            usr_holding_list = []
            usr_holding_dict = db.execute(
                "SELECT symbol FROM portfolio WHERE uid = ?", session["user_id"]
            )
            for row in usr_holding_dict:
                usr_holding_list.append(row["symbol"])
            # if in list, then update
            if result["symbol"] in usr_holding_list:
                share_update = (
                    db.execute(
                        "SELECT share FROM portfolio WHERE uid = ? AND symbol = ?",
                        session["user_id"],
                        result["symbol"],
                    )[0]["share"]
                    + share
                )
                db.execute(
                    "UPDATE portfolio SET share = ? WHERE uid = ? AND symbol = ?",
                    share_update,
                    session["user_id"],
                    result["symbol"],
                )

            # if not in list, then insert
            else:
                db.execute(
                    "INSERT INTO portfolio (uid, symbol, share) VALUES(?, ?, ?)",
                    session["user_id"],
                    result["symbol"],
                    share,
                )

            # log balance
            db.execute(
                "UPDATE users SET cash = ? WHERE id = ?",
                usr_balance - cost,
                session["user_id"],
            )

            # return to index page
            return redirect("/")

    # Default page
    else:
        return render_template("buy.html")


# History
@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # query db to get histroy
    history = db.execute(
        "SELECT * FROM history WHERE uid = ? ORDER BY hid ASC", session["user_id"]
    )

    # change format for price
    for row in history:
        row["price"] = usd(row["price"])

    # render html
    return render_template("history.html", history=history)


# Login
@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


# Logout
@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


# Quote
@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # enter quote
    if request.method == "GET":
        return render_template("quote.html")

    # show results
    elif request.method == "POST":
        result = lookup(request.form.get("symbol"))
        if result == None:
            return apology("Invalid Symbol")
        else:
            result["price"] = usd(result["price"])
            print(result)
            return render_template("quoted.html", result=result)


# Register
@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # process post
    if request.method == "POST":
        # check whether username is empty
        if not request.form.get("username"):
            return apology("Please enter a username.")

        # check whether username exists
        exist_usr_name_dict = db.execute("SELECT username FROM users")
        exist_usr_name_list = []
        for usr in exist_usr_name_dict:
            exist_usr_name_list.append(usr["username"])
        if request.form.get("username") in exist_usr_name_list:
            return apology("User name already exists.")

        # check whether password is empty
        if not request.form.get("password"):
            return apology("Please enter a password.")

        # check whether passwords match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("Passwords do not match.")

        # pass all checks, log new user
        else:
            # insert new user into db
            db.execute(
                "INSERT INTO users (username, hash) VALUES(?, ?)",
                request.form.get("username"),
                generate_password_hash(request.form.get("password")),
            )

            # redirect to homepage after registration
            return redirect("/")

    # enter registration page
    else:
        return render_template("register.html")


# Sell
@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # get portfolio info
    portfolio_info = db.execute(
        "SELECT * FROM portfolio WHERE uid = ?", session["user_id"]
    )

    # current holding list
    usr_holding_list = []
    for row in portfolio_info:
        usr_holding_list.append(row["symbol"])

    # process sell request
    if request.method == "POST":
        # validate symbol
        symbol = request.form.get("symbol")
        if symbol not in usr_holding_list:
            return apology("Invalid symbol")

        # validate shares
        share = float(request.form.get("shares"))
        current_share = db.execute(
            "SELECT share FROM portfolio WHERE uid = ? AND symbol = ?",
            session["user_id"],
            symbol,
        )[0]["share"]
        if share < 0 or share > current_share:
            return apology("Invalid share")

        # all check passed, process sell
        else:
            # get stock info
            result = lookup(symbol)

            # log sell history
            db.execute(
                "INSERT INTO history (uid, symbol, share, price, time) VALUES(?, ?, ?, ?, ?)",
                session["user_id"],
                result["symbol"],
                -share,
                result["price"],
                datetime.now(),
            )

            # log portfolio

            # calculate new share holding
            share_update = current_share - share

            # if not all sold, then update
            if share_update > 0:
                db.execute(
                    "UPDATE portfolio SET share = ? WHERE uid = ? AND symbol = ?",
                    share_update,
                    session["user_id"],
                    result["symbol"],
                )

            # if all sold, delete line
            elif share_update == 0:
                db.execute(
                    "DELETE FROM portfolio WHERE uid = ? AND symbol = ?",
                    session["user_id"],
                    result["symbol"],
                )

            # log balance
            sell_value = share * result["price"]
            usr_balance = db.execute(
                "SELECT cash FROM users WHERE id = ?", session["user_id"]
            )[0]["cash"]
            db.execute(
                "UPDATE users SET cash = ? WHERE id = ?",
                usr_balance + sell_value,
                session["user_id"],
            )

            # return to index page
            return redirect("/")

    # default page
    else:
        # render template
        return render_template("sell.html", portfolio_info=portfolio_info)
