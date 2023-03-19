import math


def f1(x):
    return 2*x**3-3*x**2+5*x-9


def f2(x):
    return math.sin(x)


def f3(x):
    return math.exp(-x)


functions = [f1, f2, f3]


def rectangle_method(f, a, b, n, mode='middle'):
    h = (b - a) / n
    integral = 0
    for i in range(n):
        if mode == 'left':
            x = a + i * h
        elif mode == 'right':
            x = a + (i + 1) * h
        else:
            x = a + (i + 0.5) * h
        integral += f(x) * h
    return integral


def trapezoid_method(f, a, b, n):
    h = (b - a) / n
    integral = (f(a) + f(b)) / 2
    for i in range(1, n):
        x = a + i * h
        integral += f(x)
    integral *= h
    return integral


def simpson_method(f, a, b, n):
    h = (b - a) / n
    integral = f(a) + f(b)
    for i in range(1, n):
        x = a + i * h
        integral += (3 - (-1) ** i) * f(x)
    integral *= h / 3
    return integral


methods = {
    'rectangle_left': lambda f, a, b, n: rectangle_method(f, a, b, n, 'left'),
    'rectangle_right': lambda f, a, b, n: rectangle_method(f, a, b, n, 'right'),
    'rectangle_middle': rectangle_method,
    'trapezoid': trapezoid_method,
    'simpson': simpson_method
}


def integrate(f, a, b, eps, method):
    n = 4
    integral_n = method(f, a, b, n)
    while True:
        n *= 2
        integral_2n = method(f, a, b, n)
        if abs(integral_2n - integral_n) / 3 < eps:
            break
        integral_n = integral_2n
    return integral_2n, n


if __name__ == '__main__':
    print("Выберите функцию для интегрирования:")
    for i, func in enumerate(functions, 1):
        print(f"{i}. {func.__name__}")
    func_idx = int(input()) - 1
    selected_function = functions[func_idx]

    print("Введите пределы интегрирования a и b:")
    a, b = map(float, input().split())

    print("Введите точность вычисления:")
    eps = float(input())

    print("Выберите метод интегрирования:")
    for i, method_name in enumerate(methods, 1):
        print(f"{i}. {method_name}")
    method_idx = int(input()) - 1
    selected_method = methods[list(methods.keys())[method_idx]]

    integral, n = integrate(selected_function, a, b, eps, selected_method)
    print(f"Значение интеграла: {integral}")
    print(f"Число разбиений интервала интегрирования для достижения требуемой точности: {n}")
