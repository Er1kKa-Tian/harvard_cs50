import re
import sys


def main():
    print(validate(input("IPv4 Address: ")))


def validate(ip):
    if matches := re.search(r"^(\d+)\.(\d+)\.(\d+)\.(\d+)$", ip):
        for i in range(1, 5):
            if int(matches[i]) < 0 or int(matches[i]) > 255:
                return False
            
        return True
    else:
        return False


if __name__ == "__main__":
    main()
