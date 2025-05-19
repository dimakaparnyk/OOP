#include <iostream>
#include "DichotomyMethod.h"
#include "NewtonMethod.h"

using namespace std;

int main() {
    // Вхідні дані
    double x;

    // Створення об'єкта для методу дихотомії
    DichotomyMethod dichotomy;
    dichotomy.setVolumes(1.0, 3.0);  // Зміна параметрів
    dichotomy.setTolerance(1e-6);  // Зміна точності
    int iterationsDichotomy = dichotomy.count(x);
    cout << "Dichotomy Method: Root = " << x << ", Iterations = " << iterationsDichotomy << endl;

    // Створення об'єкта для методу Ньютона
    NewtonMethod newton;
    newton.setInitialGuess(0.1);  // Зміна початкового наближення
    newton.setTolerance(1e-6);  // Зміна точності
    int iterationsNewton = newton.count(x);
    cout << "Newton Method: Root = " << x << ", Iterations = " << iterationsNewton << endl;

    return 0;
}
