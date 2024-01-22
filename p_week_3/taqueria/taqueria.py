def main():

    MENU = {
        "Baja Taco": 4.25,
        "Burrito": 7.50,
        "Bowl": 8.50,
        "Nachos": 11.00,
        "Quesadilla": 8.50,
        "Super Burrito": 8.50,
        "Super Quesadilla": 9.50,
        "Taco": 3.00,
        "Tortilla Salad": 8.00
    }

    cost = 0

    while True:
        try:
            usr_input = input("Item: ").title()
            if usr_input in MENU:
                cost += MENU[usr_input]
                print(f"Total: ${cost:.2f}")
        except EOFError:
            print()
            return 0

if __name__ == "__main__":
    main()
