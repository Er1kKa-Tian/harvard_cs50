from PIL import Image, ImageOps
import sys


def main():
    if len(sys.argv) != 3:
        sys.exit("Incorrect number of arguments")

    input_file, output_file = sys.argv[1], sys.argv[2]

    input_type = input_file.split(".")[1]
    output_type = output_file.split(".")[1]

    if input_type != output_type:
        sys.exit("Inconsistent types")
    elif input_type not in ("jpg", "jpeg", "png"):
        sys.exit("Unsupported file type")
    else:
        fit = Image.open("shirt.png")
        try:
            with Image.open(input_file) as input:
                input = ImageOps.fit(input, fit.size)
                input.paste(fit, fit)
                input.save(output_file)
        except FileNotFoundError:
            sys.exit("Input file does not exist.")


if __name__ == "__main__":
    main()
