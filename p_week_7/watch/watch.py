import re
import sys


def main():
    print(parse(input("HTML: ")))


def parse(s):
    if url := re.search(
        r"src=\"https?:\/\/(?:www\.)?youtube\.\w+\/embed\/([^\"]+)\"", s, re.IGNORECASE
    ):
        return "https://youtu.be/" + url.group(1)
    else:
        return None


if __name__ == "__main__":
    main()
