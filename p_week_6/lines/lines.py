import sys


def main():
    target_file = validate_input()
    counter = 0
    for line in target_file:
        if line.strip() == "" or line.strip()[0] == "#":
            continue
        else:
            counter += 1
    print(counter)
    target_file.close()


def validate_input():
    if len(sys.argv) < 2:
        sys.exit("Too few command-line arguments")
    elif len(sys.argv) > 2:
        sys.exit("Too many command-line arguments")
    elif sys.argv[1][-3:] != ".py":
        sys.exit("Not a Python file")
    else:
        try:
            return open(sys.argv[1], "r")
        except FileNotFoundError:
            sys.exit("File does not exist")


if __name__ == "__main__":
    main()
