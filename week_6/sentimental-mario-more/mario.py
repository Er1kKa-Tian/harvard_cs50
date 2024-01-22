# TODO


def main():
    height = get_height()
    print_pyramid(height)


def get_height():
    while True:
        try:
            height = int(input("Height: "))
            if height in range(1, 9, 1):
                break
        except ValueError:
            print("Input an integer in [1, 8]")

    return height


def print_pyramid(height):
    for i in range(1, height + 1, 1):
        print(" " * (height - i) + "#" * i + "  " + "#" * i)


if __name__ == "__main__":
    main()
