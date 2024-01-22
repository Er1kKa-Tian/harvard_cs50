import csv
import sys
import tabulate


def main():
    # Parse data from file
    result_list = []
    target_file = validate_input()
    for line in csv.DictReader(target_file):
        result_list.append(line)
    target_file.close()

    # Process data
    headers = list(result_list[0].keys())
    table_main = []
    for dict in result_list:
        table_main.append(list(dict.values()))

    # Display
    print(tabulate.tabulate(table_main, headers, tablefmt="grid"))


def validate_input():
    if len(sys.argv) < 2:
        sys.exit("Too few command-line arguments")
    elif len(sys.argv) > 2:
        sys.exit("Too many command-line arguments")
    elif sys.argv[1][-4:] != ".csv":
        sys.exit("Not a CSV file")
    else:
        try:
            return open(sys.argv[1])
        except FileNotFoundError:
            sys.exit("File does not exist")


if __name__ == "__main__":
    main()
