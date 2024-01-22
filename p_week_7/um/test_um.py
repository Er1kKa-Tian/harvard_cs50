import pytest
from um import count


def test_count_words():
    assert count("humm") == 0
    assert count("umberlla um is um") == 2
    assert count("um") == 1


def test_count_cases():
    assert count("Um UM um") == 3
    assert count("uM") == 1


def test_count_etc():
    assert count("um!") == 1
    assert count("~UM~") == 1
    assert count(" um ") == 1
