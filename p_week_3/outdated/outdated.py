MONTHS = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]

def main():

    while True:
        usr_input = input("Date: ").strip()
        if usr_input.find(" ") != -1 and usr_input.find(",") != -1:
            date_list = usr_input.split(" ")
            try:
                month = MONTHS.index(date_list[0]) + 1
                if month <= 0 or month > 12:
                    continue
                day = int(date_list[1].replace(",", ""))
                if day <= 0 or day > 31:
                    continue
                year = int(date_list[2])
                break
            except ValueError:
                continue
        elif usr_input.find("/") != -1:
            try:
                date_list = usr_input.split("/")
                month = int(date_list[0])
                if month <= 0 or month > 12:
                    continue
                day = int(date_list[1])
                if day <= 0 or day > 31:
                    continue
                year = int(date_list[2])
                break
            except ValueError:
                continue
        else:
            continue

    print(f"{year}-{month:02d}-{day:02d}")


if __name__ == "__main__":
    main()
