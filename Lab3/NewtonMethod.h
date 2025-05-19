#pragma once
#include <iostream>
#include <cmath>

#ifndef NEWTON_METHOD_CLASS_H
#define NEWTON_METHOD_CLASS_H

class NewtonMethod {
private:
    double x0, eps;

public:
    // Конструктор
    NewtonMethod(void);
    ~NewtonMethod(void);

    // Функція для пошуку кореня
    double f(double x);

    // Похідна функції для методу Ньютона
    double df(double x);

    // Метод для знаходження кореня
    int count(double& x);

    // Методи для зміни параметрів
    void setInitialGuess(double vol_x0);
    void setTolerance(double vol_eps);
};

#endif
