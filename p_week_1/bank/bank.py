def main():
    usr_input = input("Greeting: ").lower().strip()
    if usr_input[0:5] == "hello":
        money = 0
    elif usr_input in ["how are you doing?", "how you doing?", "hey"]:
        money = 20
    else:
        money = 100
    print(f"${money}")


if __name__ == "__main__":
    main()
