def main():

    camel_string = input("Camel Case: ").strip()

    snake_string = ""

    for i in range(len(camel_string)):
        if camel_string[i].islower():
            snake_string += camel_string[i]
        else:
            snake_string += ( '_' + camel_string[i].lower())

    print(f"Snake Case: {snake_string}")


if __name__ == "__main__":
    main()
