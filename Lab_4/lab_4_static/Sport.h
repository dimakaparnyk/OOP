#ifndef SPORT_H
#define SPORT_H

#include <string>
#include <iostream>
using namespace std;

class Sport {
protected:
    string name;
    int participants;  // Кількість учасників
public:
    Sport(string n, int p);  // Конструктор
    void displayInfo();  // Метод для виведення інформації (без virtual)
    void start();  // Метод start без параметрів
    ~Sport();  // Звичайний деструктор (без virtual)
};

// Клас для тренажерного залу
class Gym : public Sport {
private:
    string equipment;  // Обладнання для тренування
public:
    Gym(string n, int p, string e);
    void displayInfo();
    void start();
};

// Клас для футболу
class Football : public Sport {
public:
    Football(string n, int p);
    void displayInfo();
    void start();
};

// Клас для баскетболу
class Basketball : public Sport {
public:
    Basketball(string n, int p);
    void displayInfo();
    void start();
};

// Клас для плавання
class Swimming : public Sport {
private:
    string poolType;  // Тип басейну
public:
    Swimming(string n, int p, string pool);
    void displayInfo();
    void start();
};

#endif