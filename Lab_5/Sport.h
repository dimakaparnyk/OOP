#ifndef SPORT_H
#define SPORT_H

#include <string>
#include <iostream>
using namespace std;

// Базовий клас для всіх видів фізичної активності
class PhysicalActivity {
protected:
    string type;
public:
    PhysicalActivity(string t);
    virtual void displayInfo();
    virtual ~PhysicalActivity();
};

// Базовий клас для спорту
class Sport : virtual public PhysicalActivity {
protected:
    string name;
    int participants;  // Кількість учасників
public:
    Sport(string t, string n, int p);  // Конструктор
    virtual void displayInfo() override;  // Віртуальний метод для виведення інформації
    virtual void start() = 0;  // Віртуальний метод для старту спорту
    virtual ~Sport();  // Деструктор
};

// Базовий клас для командних видів спорту
class TeamSport : virtual public Sport {
protected:
    int teams;
public:
    TeamSport(string t, string n, int p, int tm);
    virtual void displayInfo() override;
    virtual ~TeamSport();
};

// Базовий клас для видів спорту з обладнанням
class EquipmentSport : virtual public Sport {
protected:
    string equipment;
public:
    EquipmentSport(string t, string n, int p, string e);
    virtual void displayInfo() override;
    virtual ~EquipmentSport();
};

// Клас для тренажерного залу
class Gym : public EquipmentSport {
public:
    Gym(string n, int p, string e);
    void displayInfo() override;
    void start() override;
    ~Gym();
};

// Клас для футболу - тепер це командний вид спорту
class Football : public TeamSport {
public:
    Football(string n, int p);
    void displayInfo() override;
    void start() override;
    ~Football();
};

// Клас для баскетболу - тепер це командний вид спорту з обладнанням
class Basketball : public TeamSport, public EquipmentSport {
public:
    Basketball(string n, int p);
    void displayInfo() override;
    void start() override;
    ~Basketball();
};

// Клас для плавання
class Swimming : virtual public Sport {
protected:  // змінюємо з private на protected для доступу з Triathlon
    string poolType;  // Тип басейну
public:
    Swimming(string n, int p, string pool);
    void displayInfo() override;
    void start() override;
    ~Swimming();
};

// Клас для багатоборства - успадковує від трьох батьківських класів
class Triathlon : public Swimming, public Gym, public TeamSport {
public:
    Triathlon(string n, int p, string pool, string e);
    void displayInfo() override;
    void start() override;
    ~Triathlon();
};

#endif
