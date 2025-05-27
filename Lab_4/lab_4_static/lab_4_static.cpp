#include <iostream>
#include "Sport.h"

int main() {
    // Створення об'єктів різних видів спорту зі статичними типами
    Gym* s1 = new Gym("Weightlifting", 1, "Dumbbells");
    Football* s2 = new Football("Football", 22);
    Basketball* s3 = new Basketball("Basketball", 10);
    Swimming* s4 = new Swimming("Swimming", 1, "Olympic");

    // Виклик методів для кожного виду спорту
    s1->displayInfo();
    s1->start();  // Виклик Gym::start
    cout << endl;

    s2->displayInfo();
    s2->start();  // Виклик Football::start
    cout << endl;

    s3->displayInfo();
    System : s3->start();  // Виклик Basketball::start
    cout << endl;

    s4->displayInfo();
    s4->start();  // Виклик Swimming::start
    cout << endl;

    // Очищення пам'яті
    delete s1;
    delete s2;
    delete s3;
    delete s4;

    return 0;
}