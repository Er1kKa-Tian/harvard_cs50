import inflect

p = inflect.engine()


def main():
    names = []
    while True:
        try:
            names.append(input("Name: "))
        except EOFError:
            print("\nAdieu, adieu, to " + p.join(names))
            return 0


if __name__ == "__main__":
    main()
