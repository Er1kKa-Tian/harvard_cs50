# TODO

import re


def main():
    card = get_card()
    global category
    category = cat(card)
    valid(card)
    print(category)


def get_card():
    pattern = r"^\d+$"
    while True:
        card = input("Number: ")
        if re.match(pattern, card) != None:
            return card


def cat(card):
    if (len(card) == 15) & (card[0:2] in ["34", "37"]):
        return "AMEX"
    elif (len(card) == 16) & (card[0:2] in ["51", "52", "53", "54", "55"]):
        return "MASTERCARD"
    elif (len(card) in [13, 16]) & (card[0] == "4"):
        return "VISA"
    else:
        return "INVALID"


def valid(card):
    sum = 0
    length = len(card)
    for i in range(length):
        if i % 2 == 0:
            sum += int(card[length - 1 - i])
        else:
            if int(card[length - 1 - i]) < 5:
                sum += int(card[length - 1 - i]) * 2
            else:
                sum += 1 + (int(card[length - 1 - i]) * 2 % 10)
    if sum % 10 != 0:
        global category
        category = "INVALID"


if __name__ == "__main__":
    main()
