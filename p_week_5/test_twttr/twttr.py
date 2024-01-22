def main():
    usr_input = input("Input: ")
    print(f"Output: {shorten(usr_input)}")


def shorten(word):
    for element in ["a", "e", "i", "o", "u"]:
        word = word.replace(element, "")
        word = word.replace(element.upper(), "")

    return word


if __name__ == "__main__":
    main()
