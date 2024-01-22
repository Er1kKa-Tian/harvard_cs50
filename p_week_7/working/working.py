import re
import sys


def main():
    print(convert(input("Hours: ")))


def convert(s):
    if match := re.fullmatch(
        r"(\d+):?(\d+)?\s(AM|PM)\sto\s(\d+):?(\d+)?\s(AM|PM)", s, re.IGNORECASE
    ):
        time1_h, time1_m, time1_type, time2_h, time2_m, time2_type = match.groups()
        if time1_m == None:
            time1_m = "00"
        if time2_m == None:
            time2_m = "00"
        if (
            not 0 < int(time1_h) <= 12
            or not 0 <= int(time1_m) <= 59
            or not 0 < int(time2_h) <= 12
            or not 0 <= int(time2_m) <= 59
        ):
            raise ValueError("Invalid Time")
        else:
            match time1_type:
                case "AM":
                    if time1_h == "12":
                        time1 = f"00:{time1_m}"
                    else:
                        time1 = f"{int(time1_h):02d}:{time1_m}"
                case "PM":
                    if time1_h == "12":
                        time1 = f"12:{time1_m}"
                    else:
                        time1 = f"{int(time1_h)+12}:{time1_m}"
            match time2_type:
                case "AM":
                    if time2_h == "12":
                        time2 = f"00:{time2_m}"
                    else:
                        time2 = f"{int(time2_h):02d}:{time2_m}"
                case "PM":
                    if time2_h == "12":
                        time2 = f"12:{time2_m}"
                    else:
                        time2 = f"{int(time2_h)+12}:{time2_m}"
            return f"{time1} to {time2}"
    else:
        raise ValueError("Invalid Input")


if __name__ == "__main__":
    main()
