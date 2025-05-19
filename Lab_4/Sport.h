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
    virtual void displayInfo();  // Віртуальний метод для виведення інформації

    // динамічний поліморфізм
    // virtual void start() = 0;  // Віртуальний метод для старту спорту

    // Статичний поліморфізм (перевантаження методу start)
    virtual void start(int equipmentCount) {
        cout << "Starting with equipment count: " << equipmentCount << endl;
    }

    virtual ~Sport();  // Деструктор
};

// Клас для тренажерного залу
class Gym : public Sport {
private:
    string equipment;  // Обладнання для тренування
public:
    Gym(string n, int p, string e);
    void displayInfo() override;

    // віртуальний метод для динамічного поліморфізму
    // void start() override;

    // Перевантажуємо метод start для статичного поліморфізму
    void start(int equipmentCount) override {
        cout << "Starting gym workout with " << equipment << " and " << equipmentCount << " pieces of equipment." << endl;
    }
};

// Клас для футболу
class Football : public Sport {
public:
    Football(string n, int p);
    void displayInfo() override;

    // віртуальний метод для динамічного поліморфізму
    // void start() override;

    // Перевантажуємо метод start для статичного поліморфізму
    void start(int equipmentCount) override {
        cout << "Starting football game with " << equipmentCount << " players." << endl;
    }
};

// Клас для баскетболу
class Basketball : public Sport {
public:
    Basketball(string n, int p);
    void displayInfo() override;

    // віртуальний метод для динамічного поліморфізму
    // void start() override;

    // Перевантажуємо метод start для статичного поліморфізму
    void start(int equipmentCount) override {
        cout << "Starting basketball game with " << equipmentCount << " players." << endl;
    }
};

// Клас для плавання
class Swimming : public Sport {
private:
    string poolType;  // Тип басейну
public:
    Swimming(string n, int p, string pool);
    void displayInfo() override;

    // віртуальний метод для динамічного поліморфізму
    // void start() override;

    // Перевантажуємо метод start для статичного поліморфізму
    void start(int equipmentCount) override {
        cout << "Starting swimming in " << poolType << " pool with " << equipmentCount << " swimmers." << endl;
    }
};

#endif
