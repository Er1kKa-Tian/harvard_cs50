tanks = [
    {"name": "E100", "class": "ht"},
    {"name": "E50", "class": "mt"},
    {"name": "E75", "class": "ht"}
]

def main():
    yell("dsaw", "2e", "21edwasdasf")
    print(ht(tanks))


def yell(*words):
    uppercased = [word.upper() for word in words]
    print(*uppercased)


def ht(tanks):
    return [tank["name"] for tank in tanks if tank["class"] == "ht"]


if __name__ == "__main__":
    main()
