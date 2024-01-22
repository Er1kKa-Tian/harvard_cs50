import random


def main():
    level = get_level()
    score = 0
    for _ in range(10):
        score += question(level)
    print(f"Score: {score}")


def get_level():
    while True:
        level = input("Level: ")
        if level in ["1", "2", "3"]:
            return int(level)


def generate_integer(level):
    match level:
        case 1:
            return random.randint(0, 9)
        case 2:
            return random.randint(10, 99)
        case 3:
            return random.randint(100, 999)


def question(level):
    a = generate_integer(level)
    b = generate_integer(level)
    ans = a + b
    temp = 0
    while True:
        temp += 1
        usr_ans = input(f"{a} + {b} = ")
        try:
            usr_ans = int(usr_ans)
        except ValueError:
            print("EEE")
            continue
        if usr_ans == ans:
            return 1
        elif temp < 3:
            print("EEE")
        else:
            print(f"{a} + {b} = {ans}")
            return 0


if __name__ == "__main__":
    main()
