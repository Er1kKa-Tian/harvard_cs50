from datetime import date, timedelta
import inflect
import re
import sys


p = inflect.engine()


def main():
    birthday = get_birthday()
    print(convert(date.today(), birthday))


def get_birthday():
    raw_input = input("Enter your birthday in YYYY-MM-DD format: ")
    if match := re.fullmatch(r"(\d\d\d\d)-(\d\d)-(\d\d)", raw_input):
        return date(int(match.group(1)), int(match.group(2)), int(match.group(3)))
    else:
        sys.exit("Invalid date syntax")


def convert(update, lowdate):
    time_delta = int((update - lowdate) / timedelta(minutes=1))
    return f"{p.number_to_words(time_delta, andword="")} minutes".capitalize()


if __name__ == "__main__":
    main()
