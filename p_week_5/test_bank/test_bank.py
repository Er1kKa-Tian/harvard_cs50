from bank import value


def test_value_0():
    assert value("hello www") == 0
    assert value("hEllo www") == 0


def test_value_20():
    assert value("hi!") == 20
    assert value("Hi!") == 20


def test_value_100():
    assert value("114514") == 100
