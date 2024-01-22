def total(thousand, hundred, ten, one):
    return 1000 * thousand + 100 * hundred + 10 * ten + 1 * one


list_record = [1, 1, 4, 5]
dict_record = {"thousand": 1, "hundred": 1, "ten": 4, "one": 5}


print(total(*list_record))
print(total(**dict_record))
