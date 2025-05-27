#include "DichotomyMethod.h"

// Конструктор
DichotomyMethod::DichotomyMethod(void) : a(0.0), b(0.0), eps(0.0) {
}

// Деструктор
DichotomyMethod::~DichotomyMethod(void) {

}

double DichotomyMethod::f(double x) {
    return x - 2 + sin(1 / x);  // Приклад: f(x) = x - 2 + sin(1/x)
}

//(int a, int b) — це параметри лямбди.
//
//-> int — це тип повернення(не обов'язково, якщо тип можна вивести автоматично).
//
//{ return a + b; } — це тіло функції.
//f(x)[] — це capture list, де можна визначити, які змінні з зовнішнього контексту доступні всередині лямбда

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
