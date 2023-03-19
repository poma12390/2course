import numpy as np

import math


def f1(x):
    return 2 * x ** 3 - 3 * x ** 2 + 5 * x - 9


def left_rectangles(func, a, b, n):
    h = (b - a) / n
    return h * sum(func(a + i * h) for i in range(n))


def right_rectangles(func, a, b, n):
    h = (b - a) / n
    return h * sum(func(a + (i + 1) * h) for i in range(n))


def middle_rectangles(func, a, b, n):
    h = (b - a) / n
    return h * sum(func(a + (i + 0.5) * h) for i in range(n))


def trapezoidal(func, a, b, n):
    h = (b - a) / n
    return h * (0.5 * (func(a) + func(b)) + sum(func(a + i * h) for i in range(1, n)))


def simpson(func, a, b, n):
    h = (b - a) / (2 * n)
    return h / 3 * (func(a) + func(b) + 4 * sum(func(a + (2 * i - 1) * h) for i in range(1, n + 1)) + 2 * sum(
        func(a + 2 * i * h) for i in range(1, n)))


def runge_rule(method, func, a, b, tol):
    n = 1
    prev_res = method(func, a, b, n)
    n *= 2
    curr_res = method(func, a, b, n)

    while abs(curr_res - prev_res) / 3 > tol:
        n *= 2
        prev_res = curr_res
        curr_res = method(func, a, b, n)

    return curr_res, n


methods = {
        "left_rectangles": left_rectangles,
        "right_rectangles": right_rectangles,
        "middle_rectangles": middle_rectangles,
        "trapezoidal": trapezoidal,
        "simpson": simpson
    }

a, b = map(float, input("Enter the bounds of the integral: ").split())
tol = float(input("Enter the exp:"))

print("Choose an integration method:")
for i, method in enumerate(methods.keys()):
    print(f"{i + 1}: {method}")
choice = int(input("Enter the number of your choice: ")) - 1
method_name = list(methods.keys())[choice]
method = methods[method_name]

result, n = runge_rule(method, f1, a, b, tol)
print(f"Result: {result}")
print(f"Number of subdivisions:{n}")
