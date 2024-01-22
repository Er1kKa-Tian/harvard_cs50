from numb3rs import validate
import pytest


def test_validate_range():
    assert validate("1.1.1.1") == True
    assert validate("0.0.0.0") == True
    assert validate("255.255.255.255") == True
    assert validate("256.1.1.1") == False
    assert validate("1.1.1.256") == False


def test_validate_format():
    assert validate("1.1.1") == False
    assert validate("cat") == False
    assert validate("1.1.1.1.1") == False
