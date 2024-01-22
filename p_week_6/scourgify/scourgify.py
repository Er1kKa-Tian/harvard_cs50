import csv
import sys


def main():
    validate_and_open()
    input_reader = csv.DictReader(input_file)
    result = []
    for line in input_reader:
        name_list = line["name"].replace(" ", "").split(",")
        result.append({"first": name_list[1], "last": name_list[0], "house": line["house"]})
    input_file.close()
    output_file = open(sys.argv[2], "w")
    output_writer = csv.DictWriter(output_file, fieldnames=list(result[0].keys()))
    output_writer.writeheader()
    for person in result:
        output_writer.writerow(person)
    output_file.close()


def validate_and_open():
    if len(sys.argv) < 3:
        sys.exit("Too few command-line arguments")
    elif len(sys.argv) > 3:
        sys.exit("Too many command-line arguments")
    elif sys.argv[1][-4:] != ".csv" or sys.argv[2][-4:] != ".csv":
        sys.exit("Not CSV files")
    else:
        try:
            global input_file
            input_file = open(sys.argv[1], "r")
        except FileNotFoundError:
            sys.exit(f"Could not read {sys.argv[1]}")


if __name__ == "__main__":
    main()
