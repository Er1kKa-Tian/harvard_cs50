def main():

    amount_due = 50

    while True:
        print(f"Amount Due: {amount_due}")
        insert_coin = int(input("Insert Coin: "))

        match insert_coin:
            case 5 | 10 | 25:
                amount_due -= insert_coin
            case _:
                continue

        if amount_due <= 0:
            break

    print(f"Change Owed: %i" %(-amount_due))


if __name__ == "__main__":
    main()
