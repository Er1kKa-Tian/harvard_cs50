tanks = [
    {"name": "E100", "class": "ht"},
    {"name": "E50", "class": "mt"},
    {"name": "E75", "class": "ht"}
]


def is_ht(tank):
    return tank["class"] == "ht"


ht = filter(is_ht, tanks)
ht = filter(lambda tank: tank["class"] == "ht", tanks) # equivalent as above

print(sorted(ht, key=lambda tank: tank["name"]))
