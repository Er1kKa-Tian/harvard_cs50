class Tank:
    # Initialisation
    def __init__(self, name, type, status="alive"):
        # we no longer need to validate status when we have the validation process included in the setter
        self.name = name
        self.type = type
        self.status = status

    # Rep as a string
    def __str__(self):
        return f"{self.type} {self.name} ({self.status})"

    # Constructor
    @classmethod
    def get(cls):
        name = input("Name: ")
        type = input("Type: ")
        status = input("Status: ")
        return cls(name, type, status)

    # Name getter
    @property
    def name(self):
        return self._name

    # Name setter
    @name.setter
    def name(self, name):
        if name not in ["E100", "E75"]:
            raise ValueError("Not a valid tank here")
        else:
            self._name = name

    # Status getter (has to be the same name as the attribute to prevent the usr from access it dirctly)
    @property
    def status(self):
        return (
            self._status
        )  # we cannot have an instance vairiable and a function with the same name, so we add a "_" to indicate this is an instance variable

    # Status setter
    @status.setter
    def status(self, status):
        if status not in ["alive", "dead"]:
            raise ValueError("Status not allowed")
        else:
            self._status = status

    # shell
    def shell(self):
        match self.name:
            case "E100":
                return "150mm shell"
            case "E75":
                return "128mm shell"
            case _:
                return "Unknown shell"


def main():
    # constructor
    tank_1 = Tank("E100", "Heavy Tank")
    # tank_1.status = "flying" # however, we can circumvent this check by doing 'tank_1._status = "flying"'

    # instantiate an instance use the get method
    tank_2 = Tank.get()

    print(f"{tank_1} shoots a {tank_1.shell()}")


if __name__ == "__main__":
    main()
