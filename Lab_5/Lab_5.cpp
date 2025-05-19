#include <iostream>
#include "Sport.h"  
using namespace std;

int main() {
    cout << "\n=== Створення об'єкту класу Gym ===" << endl;
    Sport* s1 = new Gym("Weightlifting", 1, "Dumbbells");
    s1->displayInfo();
    s1->start();
    cout << endl;

    cout << "\n=== Створення об'єкту класу Football ===" << endl;
    Sport* s2 = new Football("Football", 22);
    s2->displayInfo();
    s2->start();
    cout << endl;

    cout << "\n=== Створення об'єкту класу Basketball (множинне успадкування) ===" << endl;
    Sport* s3 = new Basketball("Basketball", 10);
    s3->displayInfo();
    s3->start();
    cout << endl;

    cout << "\n=== Створення об'єкту класу Swimming ===" << endl;
    Sport* s4 = new Swimming("Swimming", 1, "Olympic");
    s4->displayInfo();
    s4->start();
    cout << endl;

    cout << "\n=== Створення об'єкту класу Triathlon (успадкування від трьох класів) ===" << endl;
    Triathlon* s5 = new Triathlon("Triathlon", 1, "Olympic", "Bicycle");
    s5->displayInfo();
    s5->start();
    cout << endl;

    cout << "\n=== Видалення об'єктів ===" << endl;
    // Очищення пам'яті - перевіримо порядок виклику деструкторів
    delete s1;
    cout << "--------------" << endl;
    delete s2;
    cout << "--------------" << endl;
    delete s3;
    cout << "--------------" << endl;
    delete s4;
    cout << "--------------" << endl;
    delete s5;
    cout << "--------------" << endl;

    cout << "\n=== Демонстрація ромбовидного успадкування ===" << endl;
    cout << "Створюємо об'єкт Basketball для демонстрації ромбовидного успадкування:" << endl;
    // Тут явно показуємо ромбовидне успадкування
    Basketball* basketball = new Basketball("Basketball Demo", 10);
    cout << "\nКонструктори викликані в порядку: PhysicalActivity -> Sport -> TeamSport + EquipmentSport -> Basketball" << endl;
    cout << "Завдяки віртуальному успадкуванню, PhysicalActivity і Sport викликаються лише один раз" << endl;
    delete basketball;

    return 0;
}