def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if len(s) < 2 or len(s) > 6:
        return False

    elif s[0].isalpha() == False or s[1].isalpha() == False:
        return False

    elif s.find(" ") != -1 or s.find(",") != -1 or s.find(".") != -1:
        return False

    else:
        flag = -1
        for i in range(len(s)):
            if s[i].isdigit():
                flag = i
                if s[i] == "0":
                    return False
                break
        if flag == -1:
            return True
        for i in range(flag, len(s)):
            if s[i].isalpha():
                return False

    return True


if __name__ == "__main__":
    main()
