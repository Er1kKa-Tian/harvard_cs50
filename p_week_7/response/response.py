from validator_collection import checkers


def main():
    usr_input = input("What is your email address? ")
    if checkers.is_email(usr_input):
        print("Valid")
    else:
        print("Invalid")


if __name__ == "__main__":
    main()
