import pytest
from working import convert


def test_convert_format():
    with pytest.raises(ValueError):
        convert("ab AM to 12 PM")

    with pytest.raises(ValueError):
        convert("1 PM to ca PM")

    with pytest.raises(ValueError):
        convert("12:00 to 5 PM")

    with pytest.raises(ValueError):
        convert("12AM 1PM")


def test_convert_range():
    with pytest.raises(ValueError):
        convert("13 AM to 12 PM")

    with pytest.raises(ValueError):
        convert("1:60 PM to 1 PM")

    with pytest.raises(ValueError):
        convert("00:01 to 12:61 PM")

    with pytest.raises(ValueError):
        convert("00:01 AM to 00:30 PM")


def test_convert_AM():
    assert convert("9 AM to 10 AM") == "09:00 to 10:00"
    assert convert("8 AM to 12 AM") == "08:00 to 00:00"
    assert convert("12:01 AM to 12:59 AM") == "00:01 to 00:59"


def test_convert_PM():
    assert convert("9 PM to 10 PM") == "21:00 to 22:00"
    assert convert("8 PM to 12 PM") == "20:00 to 12:00"
    assert convert("12:01 PM to 12:59 PM") == "12:01 to 12:59"


def test_convert_mixed():
    assert convert("9 AM to 5 PM") == "09:00 to 17:00"
    assert convert("9:00 AM to 5:00 PM") == "09:00 to 17:00"
