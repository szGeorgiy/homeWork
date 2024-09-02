#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

// Определение типа для функций
typedef double (*func)(double);

// Уравнения
double f1(double x){
    return 0.6 * x + 3;
}
double f2(double x){
    return pow(x - 2, 3) - 1;
}
double f3(double x){
    return 3 / x;
}

// Функция нахождения корня уравнения f(x) = g(x) на отрезке a, b
int find_root(func f, func g, double a, double b, double eps, double *root, int *iterations) {
    double fa = f(a) - g(a);
    double fb = f(b) - g(b);

    if (fa * fb > 0) {
        return -1; // Невозможно найти корень, функции имеют одинаковый знак
    }

    *iterations = 0;

    while ((b - a) > 2 * eps){
        (*iterations)++;
        double c = (a + b) / 2;
        double fc = f(c) - g(c);

        if (fabs(fc) < eps) {
            *root = c;
            return 0; // Найден корень
        }

        if (fa * fc < 0) {
            b = c;  // Корень между a и c
            fb = fc;
        } else {
            a = c;  // Корень между c и b
            fa = fc;
        }
    }

    *root = (a + b) / 2; // Возвращаем итоговый корень
    return 0;
}

// Функция нахождения интеграла от функции f(x) на отрезке [a, b]
double integral(func f, double a, double b, double eps) {
    double total = 0.0;          // Общая сумма интеграла
    int intervals = 1;           // Начальное число интервалов
    double width = (b - a) / intervals; // Ширина интервала
    double last_total = -1.0;   // Предыдущее значение суммы (инициализировано на -1, чтобы войти в цикл)

    while (fabs(total - last_total) > eps) {
        last_total = total;      // Запомнить предыдущее вычисленное значение
        total = 0.0;            // Сбрасить общую сумму для нового вычисления

        for (int j = 0; j < intervals; j++) {
            double left = a + j * width;  // Левая граница текущего интервала
            double right = left + width;   // Правая граница текущего интервала

            // Вычисляем площадь и добавляем к общей сумме
            total += (f(left) + f(right)) * width / 2.0; 
        }

        // Увеличиваем количество интервалов
        intervals *= 2;             
        width = (b - a) / intervals; // Вычисляем новую ширину интервала
    }

    return total;                 // Возвращаем итоговую сумму интеграла
}

void print_help() {
    printf("Список используемых ключей\n");
    printf("Ключи:\n");
    printf("  -help               Вывод вспомогательного окна\n");
    printf("  -intersections      Вывод координат пересечения\n");
    printf("  -iterations         Вывод количеств итераций\n");
    printf("  -test               Тест функций нахождения корней и интеграла\n");
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");

    double a = 0, b = 100.0;
    double eps1 = 1e-6;
    double eps2 = 1e-6;

    if (argc < 2) {
        print_help();
        return 1;
    }

    if (strcmp(argv[1], "-help") == 0) {
        print_help();
        return 0;
    }

    if (strcmp(argv[1], "-intersections") == 0) {
        double root;
        int iterations;

        printf("Поиск пересечений...\n");

        if (find_root(f1, f2, a, b, eps1, &root, &iterations) == 0) {
            printf("Пересечение функций f1 и f2 в точке x = %f\n", root);
        } else {
            printf("Нет пересечений функций f1 и f2 в интервале [%f, %f]\n", a, b);
        }

        if (find_root(f1, f3, a, b, eps1, &root, &iterations) == 0) {
            printf("Пересечение функций f1 и f3 в точке x = %f\n", root);
        } else {
            printf("Нет пересечений функций f1 и f3 в интервале [%f, %f]\n", a, b);
        }

        if (find_root(f2, f3, a, b, eps1, &root, &iterations) == 0) {
            printf("Пересечение функций f2 и f3 в точке x = %f\n", root);
        } else {
            printf("Нет пересечений функций f2 и f3 в интервале [%f, %f]\n", a, b);
        }
    } else if (strcmp(argv[1], "-iterations") == 0) {
        double root;
        int iterations;

        if (find_root(f1, f2, a, b, eps1, &root, &iterations) == 0) {
            printf("Количество итерация для нахождения пересечений f1 и f2: %d\n", iterations);
        } else {
            printf("Нет пересечений функций f1 и f2 в интервале [%f, %f]\n", a, b);
        }

        if (find_root(f1, f3, a, b, eps1, &root, &iterations) == 0) {
            printf("Количество итерация для нахождения пересечений f1 и f3: %d\n", iterations);
        } else {
            printf("Нет пересечений функций f1 и f3 в интервале [%f, %f]\n", a, b);
        }

        if (find_root(f2, f3, a, b, eps1, &root, &iterations) == 0) {
            printf("Количество итерация для нахождения пересечений f2 и f3: %d\n", iterations);
        } else {
            printf("Нет пересечений функций f2 и f3 в интервале [%f, %f]\n", a, b);
        }
    } else if (strcmp(argv[1], "-test") == 0) {
        double root;
        int iterations;

        if (find_root(f1, f2, a, b, eps1, &root, &iterations) == 0) {
            printf("Пересечение функций f1 и f2 в точке x = %f\n", root);
        } else {
            printf("Нет пересечений функций f1 и f2\n");
        }

        if (find_root(f1, f3, a, b, eps1, &root, &iterations) == 0) {
            printf("Пересечение функций f1 и f3 в точке x = %f\n", root);
        } else {
            printf("Нет пересечений функций f1 и f3\n");
        }

        if (find_root(f2, f3, a, b, eps1, &root, &iterations) == 0) {
            printf("Пересечение функций f2 и f3 в точке x = %f\n", root);
        } else {
            printf("Нет пересечений функций f2 и f3\n");
        }

        printf("Интеграл функции f1 от %f до %f: %f\n", a, b, integral(f1, a, b, eps2));
        printf("Интеграл функции f2 от %f до %f: %f\n", a, b, integral(f2, a, b, eps2));
        printf("Интеграл функции f3 от %f до %f: %f\n", a, b, integral(f3, a, b, eps2));
    } else {
        print_help();
        return 1;
    }

    return 0;
}