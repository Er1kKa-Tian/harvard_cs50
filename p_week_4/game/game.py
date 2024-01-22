from random import randint


def main():
    level = get_level()
    guess(level)


def get_level():
    while True:
        try:
            usr_input = int(input("Level: "))
            if usr_input >= 1:
                return usr_input
            else:
                pass
        except ValueError:
            pass


def guess(level):
    answer = randint(1, level)
    while True:
        try:
            trial = int(input("Guess: "))
            if trial == answer:
                print("Just right!")
                return 0
            elif trial < answer:
                print("Too small!")
            else:
                print("Too large!")
        except ValueError:
            pass


if __name__ == "__main__":
    main()
