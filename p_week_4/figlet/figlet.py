import sys
import pyfiglet


def main():
    if len(sys.argv) == 1:
        output = pyfiglet.figlet_format(input("Input: "))
        print(f"Output:\n{output}")
    else:
        if sys.argv[1] != "-f":
            sys.exit("Invalid usage")
        else:
            try:
                f = pyfiglet.Figlet(font=sys.argv[2])
                output = f.renderText(input("Input: "))
                print(f"Output:\n{output}")
            except pyfiglet.FontNotFound:
                sys.exit("Invalid usage")


if __name__ == "__main__":
    main()
