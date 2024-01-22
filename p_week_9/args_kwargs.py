def f(*args, **kwargs):
    print(f"Positional: {args} (a tuple)")
    print(f"Named: {kwargs} (a dict)")

f(114, 514, favourite=1919810)
