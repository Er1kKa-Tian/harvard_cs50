def main():
    while True:
        try:
            print(gauge(convert(input("Fraction: "))))
            return 0
        except (ValueError, ZeroDivisionError):
            pass


def convert(fraction):
    fraction_splitted = fraction.split("/")
    a = int(fraction_splitted[0])
    b = int(fraction_splitted[1])

    if b == 0:
        raise ZeroDivisionError
    elif (a / b) > 1:
        raise ValueError
    else:
        return round((a / b) * 100)


def gauge(percentage):
    if percentage <= 1:
        return "E"
    elif percentage >= 99:
        return "F"
    else:
        return f"{percentage}%"


if __name__ == "__main__":
    main()
