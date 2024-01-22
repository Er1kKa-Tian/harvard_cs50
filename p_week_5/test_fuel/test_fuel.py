from fuel import convert, gauge
import pytest


def test_convert():
    assert convert("1/3") == 33
    assert convert("2/3") == 67

    with pytest.raises(ValueError):
        assert convert("2/1")
        assert convert("cat/dog")

    with pytest.raises(ZeroDivisionError):
        assert convert("1/0")



def test_gauge():
    assert gauge(0) == "E"
    assert gauge(1) == "E"
    assert gauge(2) == "2%"
    assert gauge(50) == "50%"
    assert gauge(98) == "98%"
    assert gauge(99) == "F"
    assert gauge(100) == "F"
