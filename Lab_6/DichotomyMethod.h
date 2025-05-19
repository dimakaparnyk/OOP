#pragma once
#include <iostream>
#include <cmath>

#ifndef DYHOTOMIA_CLASS_H
#define DYHOTOMIA_CLASS_H

class DichotomyMethod {
private:
    double a, b, eps;

public:
    // Конструктор
    DichotomyMethod(void);
    ~DichotomyMethod(void);

    // Функція для пошуку кореня
    double f(double x);

    // Метод для знаходження кореня
    int count(double& x);

    // Методи для зміни параметрів
    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);
};

#endif
