def main():

    usr_input = input("What is the Answer to the Great Question of Life, the Universe, and Everything? ")

    usr_input = usr_input.lower().replace(' ', '')

    match usr_input:
        case "42" | "forty-two" | "fortytwo":
            print("Yes")
        case _:
            print("No")

if __name__ == "__main__":
    main()
