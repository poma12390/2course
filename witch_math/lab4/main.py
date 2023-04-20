import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit


def linear_func(x, a, b):
    return a * x + b


def poly_2(x, a, b, c):
    return a * x ** 2 + b * x + c


def poly_3(x, a, b, c, d):
    return a * x ** 3 + b * x ** 2 + c * x + d


def exp_func(x, a, b, c):
    return a * np.exp(b * x) + c


def log_func(x, a, b, c):
    return a * np.log(b * x) + c


def power_func(x, a, b, c):
    return a * x ** b + c


functions = [linear_func, poly_2, poly_3, exp_func, log_func, power_func]
function_names = ['Linear', 'Polynomial (2nd degree)', 'Polynomial (3rd degree)', 'Exponential', 'Logarithmic', 'Power']

# Ввод данных
points = np.array([
    [0, 0],
    [0.2, 0.088],
    [0.4, 0.177],
    [0.6, 0.263],
    [0.8, 0.34],
    [1, 0.4],
    [1.2, 0.433],
    [1.4, 0.436],
    [1.6, 0.411],
    [1.8, 0.369],
    [2, 0.32]
])

x = points[:, 0]
y = points[:, 1]

best_fit_func = None
best_fit_params = None
min_rmse = float('inf')

# Подгонка функций и выбор наилучшей
for func, func_name in zip(functions, function_names):
    try:
        params, _ = curve_fit(func, x, y)
        y_pred = func(x, *params)
        rmse = np.sqrt(np.mean((y - y_pred) ** 2))

        if rmse < min_rmse:
            min_rmse = rmse
            best_fit_func = func
            best_fit_params = params

        print(f'{func_name} - RMSE: {rmse:.3f} - Coefficients: {params}')
    except RuntimeError:
        print(f'{func_name} - Failed to fit')

print(f'\nBest fit: {best_fit_func.__name__}')

# Построение графиков
x_range = np.linspace(x.min() - 0.2, x.max() + 0.2, 100)
plt.scatter(x, y, label='Data', color='red')

for func, func_name in zip(functions, function_names):
    try:
        params, _ = curve_fit(func, x, y)
        plt.plot(x_range, func(x_range, *params), label=func_name)
    except RuntimeError:
        pass

plt.legend()
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Function Approximations')
plt.show()
