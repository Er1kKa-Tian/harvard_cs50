from plates import is_valid


def test_is_valid_basic():
    assert is_valid("CS50") == True
    assert is_valid("1919") == False

def test_is_valid_num():
    assert is_valid("CS05") == False


def test_is_valid_end():
    assert is_valid("CS50P") == False


def test_is_valid_other():
    assert is_valid("PI3.14") == False
    assert is_valid("H") == False
    assert is_valid("OUTATIME") == False

