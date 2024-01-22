from twttr import shorten


def test_shorten_lower():
    assert shorten("1aeiou2aeks") == "12ks"


def test_shorten_upper():
    assert shorten("1AEIOU2") == "12"


def test_shorten_mixed():
    assert shorten("aeiOUAEIouDs") == "Ds"


def test_shorten_punctuations():
    assert shorten("HellO!") == "Hll!"


if __name__ == "__main__":
    main()
