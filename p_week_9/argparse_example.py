import argparse # no need to import sys

parser = argparse.ArgumentParser(description="Meow like a cat") # create a parser instance and description
parser.add_argument("-n", "--number", default=1, help="number of times to meow", type=int) # add argument -n and help
parser.add_argument('-l', '--loud', action='store_true', help="MEOW LOUDER")  # on/off flag
args = parser.parse_args() # create an args instance with argument values stored

for _ in range(args.number):
    if args.loud:
        print("MEOW")
    else:
        print("meow")
