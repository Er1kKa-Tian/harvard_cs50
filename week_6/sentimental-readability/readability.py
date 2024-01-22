# TODO


def main():
    letters_no = 0
    sentences_no = 0
    words_no = 0
    string = input("Text: ")
    words = string.split(" ")
    for i in range(len(words)):
        if words[i].isalpha() == False:
            if words[i][-1] in [".", "!", "?"]:
                sentences_no += 1
            words[i] = words[i][:-1]
            words[i] = words[i].strip(',".!?')
        words_no += 1
        letters_no += len(words[i])
        print(words[i])
    L = letters_no / words_no * 100
    S = sentences_no / words_no * 100
    # print(f"{letters_no} letters, {words_no} words, {sentences_no} sentences")
    index = round(0.0588 * L - 0.296 * S - 15.8)
    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


if __name__ == "__main__":
    main()
