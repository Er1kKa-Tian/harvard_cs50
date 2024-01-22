def main():

    my_dict = {}

    while True:
        try:
            new_item = input().upper()
            if new_item not in my_dict:
                my_dict[new_item] = 1
            else:
                my_dict[new_item] += 1
        except EOFError:
            for item in sorted(my_dict.keys()):
                print(f"{my_dict[item]} {item}")
            return 0


if __name__ == "__main__":
    main()
