def main():

    time_raw = input("What time is it? ")
    time = convert(time_raw)

    if 7 <= time <= 8:
        print("breakfast time")

    elif 12 <= time <= 13:
        print("lunch time")

    elif 18 <= time <= 19:
        print("dinner time")

    else:
        return


def convert(time):

    hour_minute = time.split(':')
    return int(hour_minute[0]) + (int(hour_minute[1]) / 60)


if __name__ == "__main__":
    main()
