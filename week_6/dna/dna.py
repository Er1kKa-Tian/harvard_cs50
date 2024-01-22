import csv
import sys


def main():
    # TODO: Check for command-line usage

    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return 1

    # TODO: Read database file into a variable

    data = []
    with open(sys.argv[1], "r") as database:
        data_reader = csv.DictReader(database)
        for person in data_reader:
            data.append(person)
    for i in range(len(data)):
        for key in data[i].keys():
            if key != "name":
                data[i][key] = int(data[i][key])

    # TODO: Read DNA sequence file into a variable

    sample_file = open(sys.argv[2], "r")
    sample_dna = sample_file.read()

    # TODO: Find longest match of each STR in DNA sequence

    sample_result = {}
    keys = list(data[0].keys())
    for STR in keys[1:]:
        sample_result[STR] = longest_match(sample_dna, STR)

    # TODO: Check database for matching profiles

    for i in range(len(data)):
        match = True
        for STR in keys[1:]:
            if sample_result[STR] != data[i][STR]:
                match = False
        if match == True:
            print(data[i]["name"])
            return 0
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
