#include "DichotomyMethod.h"

// Конструктор
DichotomyMethod::DichotomyMethod(void) {

}

// Деструктор
DichotomyMethod::~DichotomyMethod(void) {

}

double DichotomyMethod::f(double x) {
    return x - 2 + sin(1 / x);  // Приклад: f(x) = x - 2 + sin(1/x)
}

// Метод для знаходження кореня методом дихотомії
int DichotomyMethod::count(double& x) {
    int iterations = 0;  // Лічильник ітерацій
    auto f = [](double x) { return x - 2 + sin(1 / x); };  // Лямбда-вираз для f(x)

    while ((b - a) > eps) {
        double c = (a + b) / 2;
        if (f(c) == 0) {
            x = c;
            break;
        }
        if (f(a) * f(c) < 0) {
            b = c;
        }
        else {
            a = c;
        }
        x = c;
        iterations++;
    }
    return iterations;  // Повертаємо кількість ітерацій
}


// Метод для зміни обмежень
void DichotomyMethod::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

// Метод для зміни точності
void DichotomyMethod::setTolerance(double vol_eps) {
    eps = vol_eps;
}
