#include "NewtonMethod.h"

// Конструктор
NewtonMethod::NewtonMethod(void) {

}

// Деструктор
NewtonMethod::~NewtonMethod(void) {
 
}

// Функція для визначення кореня
double NewtonMethod::f(double x) {
    return x - 2 + sin(1 / x);  // f(x) = x - 2 + sin(1/x)
}

// Похідна функції
double NewtonMethod::df(double x) {
    return 1 - cos(1 / x) / (x * x);  // похідна f(x) = x - 2 + sin(1/x)
}

// Метод для знаходження кореня методом Ньютона
int NewtonMethod::count(double& x) {
    int iterations = 0;  // Лічильник ітерацій
    x = x0;
    while (abs(f(x)) > eps) {
        x = x - f(x) / df(x);
        iterations++;
    }
    return iterations;  // Повертаємо кількість ітерацій
}

// Метод для зміни початкового наближення
void NewtonMethod::setInitialGuess(double vol_x0) {
    x0 = vol_x0;
}

// Метод для зміни точності
void NewtonMethod::setTolerance(double vol_eps) {
    eps = vol_eps;
}
