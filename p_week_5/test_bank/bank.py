def main():
    usr_input = input("Greeting: ")
    print(f"${value(usr_input)}")


def value(greeting):
    greeting = greeting.lower().strip()
    if greeting[0:5] == "hello":
        money = 0
    elif greeting[0] == "h":
        money = 20
    else:
        money = 100

    return money


if __name__ == "__main__":
    main()
