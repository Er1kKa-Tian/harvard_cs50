from datetime import date
from seasons import convert


def test_convert():
    assert convert(date(2000, 1, 1), date(1999, 1, 1)) == "Five hundred twenty-five thousand, six hundred minutes"
    assert convert(date(2000, 1, 1), date(1999, 12, 31)) == "One thousand, four hundred forty minutes"
    assert convert(date(2000, 1, 1), date(1970, 1, 1)) == "Fifteen million, seven hundred seventy-eight thousand eighty minutes"
