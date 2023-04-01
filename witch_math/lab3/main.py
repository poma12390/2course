import numpy as np

import math


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


# Обработка бесконечных разрывов
def handle_infinite(f, a, b, tol):
    if a == float('-inf'):
        return runge_rule(simpson, f1, a, b, tol)
    elif b == float('inf'):
        return runge_rule(simpson, f1, a, b, tol)
    else:
        return runge_rule(simpson, f1, a, b, tol)


# Проверка на сходимость интегралов 2 рода
def check_convergence(f, a, b):
    if a == float('-inf') and b == float('inf'):
        return False
    if a == float('-inf'):
        if hasattr(f, "converges_at_inf"):
            return f.converges_at_inf
        else:
            return False
    if b == float('inf'):
        if hasattr(f, "converges_at_minus_inf"):
            return f.converges_at_minus_inf
        else:
            return False
    return True


def runge_rule(method, func, a, b, tol):
    n = 1
    prev_res = method(func, a, b, n)
    n *= 2
    curr_res = method(func, a, b, n)
    k = 2
    while abs(curr_res - prev_res) / (2 ** k - 1) > tol:
        k += 1
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

f1 = lambda x: 2 * math.log(x) ** 3 - 3 * math.cos(x) ** 2 + 5 * x - 9

a, b = map(float, input("Enter the bounds of the integral: ").split())
tol = float(input("Enter the exp:"))

print("Choose an integration method:")
for i, method in enumerate(methods.keys()):
    print(f"{i + 1}: {method}")
choice = int(input("Enter the number of your choice: ")) - 1
method_name = list(methods.keys())[choice]
method = methods[method_name]

if not check_convergence(f1, a, b):
    print("Интеграл не существует")
    exit(1)

result, n = runge_rule(method, f1, a, b, tol)
print(f"Значение интеграла: {result}")
print(f"Число разбиений интервала:{n}")

result, n = handle_infinite(f1, a, b, tol)
print(f"Значение интеграла при обработке разрывов: {result:.6f}")
print(f"Число разбиений интервала при обработке разрывов: {n}")
