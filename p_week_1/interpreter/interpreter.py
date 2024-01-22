def main():

    expression = input("Expression: ").replace(' ', '')

    for i in range(len(expression)):
        if expression[i].isdigit() == False:
            a = int(expression[:i])
            operation = expression[i]
            b = int(expression[i+1:])

    match operation:

        case "+":
            result = a + b

        case "-":
            result = a - b

        case "*":
            result = a * b

        case "/":
            result = a / b

    print(f"{result:.1f}")



if __name__ == "__main__":
    main()
