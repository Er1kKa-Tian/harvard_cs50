def main():
    n = int(input("Number: "))
    for line in generate_block(n):
        print(line)


def generate_block(n):
    for i in range(n):
        yield "#" * i  # hand back one line at a time
        # more precisely, return an "iterator"


if __name__ == "__main__":
    main()
