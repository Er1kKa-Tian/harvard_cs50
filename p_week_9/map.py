def main():
    yell("dsaw", "2e", "21edwasdasf")


def yell(*words):
    uppercased = map(str.upper, words)
    print(*uppercased)


if __name__ == "__main__":
    main()
