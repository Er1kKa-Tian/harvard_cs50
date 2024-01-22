import json
import requests
import sys


def main():
    # get correct input
    if len(sys.argv) != 2:
        sys.exit("Please enter 1 cli argument")
    else:
        try:
            usr_number = float(sys.argv[1])
        except ValueError:
            eys.exit("cli argument is not a number")

    # request
    try:
        bitcoin_info = requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
    except requests.RequestException:
        sys.exit("Fail to request bitcoin price info")

    # calculation

    info_dict = bitcoin_info.json()
    result = info_dict["bpi"]["USD"]["rate_float"] * usr_number

    # print out result
    print(f"${result:,.4f}")


if __name__ == "__main__":
    main()
