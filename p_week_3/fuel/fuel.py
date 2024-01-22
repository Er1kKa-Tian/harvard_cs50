def main():

    while True:
        try:
            input_str = input("Fraction: ")
            input_list = input_str.split('/')
            result = int(input_list[0]) / int(input_list[1])
            if result > 1:
                raise ValueError
        except (ValueError, ZeroDivisionError):
            pass
        else:
            break

    if result <= 0.01:
        print("E")
    elif result >= 0.99:
        print("F")
    else:
        print(f"{result: .0%}")


if __name__ == "__main__":
    main()
