import random

class Hat:
    # class variable
    houses = ["St Hilda's", "St Anthony", "Keble", "Kellogg"]

    # class method
    @classmethod
    def sort(cls, name):
        print(name, "is in", random.choice(cls.houses))

def main():
    Hat.sort("Er1kKa")

if __name__ == "__main__":
    main()
