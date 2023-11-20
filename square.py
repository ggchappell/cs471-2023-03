#!/usr/bin/env python3


def square(n):
    """square: take a number, return its square.

    >>> square(5)
    25
    >>> square(-3)
    9
    >>> isinstance(square(2), int)
    True
    
    """
    return n*n


def cube(n):
    """cube: take a number, return its cube.

    >>> cube(-3)
    -27

    """
    return n*n*n

if __name__ == "__main__":
    print("The square of 5 is", square(5))


