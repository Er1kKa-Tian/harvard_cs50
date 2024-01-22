from jar import Jar
import pytest
from unittest.mock import Mock


def test_creation():
    with pytest.raises(ValueError):
        jar = Jar(-1)
    with pytest.raises(ValueError):
        jar = Jar("cat")
    with pytest.raises(ValueError):
        jar = Jar(0)


def test_str():
    jar = Jar()
    assert str(jar) == ""
    jar.deposit(1)
    assert str(jar) == "🍪"
    jar.deposit(11)
    assert str(jar) == "🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪🍪"


def test_deposit():
    jar = Jar(8)
    with pytest.raises(ValueError):
        jar.deposit(9)


def test_withdraw():
    jar = Jar(2)
    jar.deposit(2)
    with pytest.raises(ValueError):
        jar.withdraw(3)
