#include <iostream>
#include "Sport.h"

int main() {
    // Створення об'єктів різних видів спорту
    Sport* s1 = new Gym("Weightlifting", 1, "Dumbbells");
    Sport* s2 = new Football("Football", 22);
    Sport* s3 = new Basketball("Basketball", 10);
    Sport* s4 = new Swimming("Swimming", 1, "Olympic");

    // Виклик методів для кожного виду спорту
    s1->displayInfo();
    s1->start(10);  // Викликаємо перевантажену версію для статичного поліморфізму
    cout << endl;

    s2->displayInfo();
    s2->start(22);
    cout << endl;

    s3->displayInfo();
    s3->start(10);
    cout << endl;

    s4->displayInfo();
    s4->start(1);  
    cout << endl;

    // Очищення пам'яті
    delete s1;
    delete s2;
    delete s3;
    delete s4;

    return 0;
}
