from emoji import emojize


def main():
    usr_input = input("Input: ")
    print(emojize(usr_input, language="alias"))


if __name__ == "__main__":
    main()
