MAX_ITER=100

def chord(f, a, b, e): #Находит
    x = (a + b)/2
    n=0
    while True:
        old_x = x
        f_a = f(a)
        f_b = f(b)
        x = (a * f_b - b * f_a) / (f_b - f_a)
        f_x = f(x)
        print("итерация", n)
        print(old_x, "x", n, "      ", x, "x", n + 1)
        n+=1
        if(n>MAX_ITER):
            print("Превышено число итераций")
            exit(1)
        if f_a * f_x <= 0:
            b = x
        else:
            a = x

        if abs(x - old_x) <= e or abs(a - b) <= e or abs(f_x) <= e:
            print("Всего итераций", n - 1)
            return x


#F-Функция а-коефициенты при x_1 x_2, e-точность
def matrix_iter(F, a, e):
    X = [1, 1]
    phi = lambda X: [(-F[i](X) + a[i] * X[i])/a[i] for i in range(len(X))]#выражение x_1 x_2
    n=0
    while True:
        old_X = X
        X = phi(old_X)
        print("итерация", n)
        print(old_X[0], "x", n, "   ", X[0], "x", n + 1, end="  ")
        print(old_X[1], "y", n, "   ", X[1], "y", n + 1)
        n+=1
        if (n > MAX_ITER):
            print("Превышено число итераций")
            exit(1)
        if (max(abs(X[0] - old_X[0]), abs(X[1]-old_X[1])) <= e):
            return X


def derivative(f, x, acc):
    return (f(x + acc) - f(x))/acc



def newton(f, df, a, b, e):
    x = (a + b)/2
    n=0
    while True:
        old_x = x
        x = old_x - f(old_x) / df(old_x)
        f_x = f(old_x)
        df_x = df(old_x)
        print("итерация", n)
        print(old_x, "x", n, "      ", x, "x", n + 1)
        n=n+1
        if (n > MAX_ITER):
            print("Превышено число итераций")
            exit(1)
        if abs(x - old_x) <= e or (abs(f_x) / abs(df_x)) <= e or abs(f_x) <= e:
            print("Всего итераций", n - 1)
            return x





def iteration_method(f, df, a, b, e):
    x = (a + b) / 2

    lam = - 1 / max(df(a), df(b))
    phi = lambda x: x + lam * f(x)
    n=0;
    while True:
        old_x = x
        x = phi(old_x)
        print("итерация", n)
        print(old_x , "x" , n ,"      ", x , "x" , n+1)
        n+=1
        if (n > MAX_ITER):
            print("Превышено число итераций")
            exit(1)
        if abs(x - old_x) <= e:
            print("Всего итераций", n-1)
            return x




#print(iteration_method(lambda x: x**3 + 2*x**2 - 5, lambda x: 3*x**2 + 4*x, 1, 2, 0.01))# простая итерация
#print(chord(lambda x: x**3 + 2*x**2 - 5, 1, 2, 0.01))#Хорды
#print(newton(lambda x: x**3 + 2*x**2 - 5,lambda x: 3*x**2 + 4*x, 1, 2, 0.01))
print(matrix_iter([lambda X: 0.1 * X[0]**2 + X[0] + 0.2*X[1]**2 - 0.3,
                   lambda X: 0.2 * X[1]**2 + X[1] + 0.1 * X[0] * X[1] - 0.7],
      [1,1], 0.01))
