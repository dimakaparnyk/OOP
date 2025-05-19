#include <cmath>
#include <iostream>
#include "triangle.h"

using namespace std;

// Функція для обчислення відстані між двома точками
double dist(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Функція для обчислення векторного добутку двох векторів
double cross(const Point& p1, const Point& p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

// Функція для обчислення площі трикутника за формулою Герона
double heronArea(const Triangle& t) {
    double a = dist(t.A, t.B), b = dist(t.B, t.C), c = dist(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Метод для обчислення площі трикутника
double Triangle::area() const {
    return heronArea(*this);
}

// Метод для перевірки, чи є трикутник виродженим за допомогою Герона
bool Triangle::isDegenerateByHeron() const {
    double areaValue = area();
    return fabs(areaValue) < 1e-6;  // Якщо площа дуже мала (близька до нуля), трикутник вироджений
}

// Метод для перевірки, чи є трикутник виродженим за допомогою векторного добутку
bool Triangle::isDegenerate() const {
    // Використовуємо векторний добуток для перевірки виродженості
    double crossProduct = cross({ B.x - A.x, B.y - A.y }, { C.x - A.x, C.y - A.y });
    return fabs(crossProduct) < 1e-6;  // Поріг для точності
}

// Метод для перевірки, чи точка знаходиться всередині трикутника
bool Triangle::contains(const Point& p) const {
    Triangle t1 = { A, B, p }, t2 = { B, C, p }, t3 = { C, A, p };
    return fabs(area() - (t1.area() + t2.area() + t3.area())) < 1e-9;
}

// Метод для перевірки, чи точка знаходиться всередині трикутника, на межі чи зовні
// Метод для перевірки, чи точка знаходиться всередині трикутника, на межі чи зовні
bool Triangle::containsAlt(const Point& p) const {
    // Вектори для сторін трикутника та точок
    Point ab = { B.x - A.x, B.y - A.y }, bc = { C.x - B.x, C.y - B.y },
        ca = { A.x - C.x, A.y - C.y }, ap = { p.x - A.x, p.y - A.y },
        bp = { p.x - B.x, p.y - B.y }, cp = { p.x - C.x, p.y - C.y };

    // Обчислення векторних добутків
    double cross1 = cross(ab, ap), cross2 = cross(bc, bp), cross3 = cross(ca, cp);

    // Поріг для точності перевірки
    const double epsilon = 1e-6;

    // Перевірка, чи точка на межі трикутника (векторний добуток дорівнює нулю або дуже близький до нуля)
    if (fabs(cross1) < epsilon || fabs(cross2) < epsilon || fabs(cross3) < epsilon) {
        // Додатково перевіряємо, чи точка лежить на межі:
        if ((p.x >= min(A.x, B.x) && p.x <= max(A.x, B.x) && p.y >= min(A.y, B.y) && p.y <= max(A.y, B.y)) ||
            (p.x >= min(B.x, C.x) && p.x <= max(B.x, C.x) && p.y >= min(B.y, C.y) && p.y <= max(B.y, C.y)) ||
            (p.x >= min(C.x, A.x) && p.x <= max(C.x, A.x) && p.y >= min(C.y, A.y) && p.y <= max(C.y, A.y))) {
            cout << "Point is on the edge of the triangle." << endl;
            return true;  // Точка на межі
        }
    }

    // Перевірка, чи точка всередині трикутника (усі добутки мають однаковий знак)
    if ((cross1 > 0 && cross2 > 0 && cross3 > 0) || (cross1 < 0 && cross2 < 0 && cross3 < 0)) {
        cout << "Point is inside the triangle." << endl;
        return true;  // Точка всередині трикутника
    }

    // Якщо точка зовні трикутника
    cout << "Point is outside the triangle." << endl;
    return false;  // Точка зовні трикутника
}

