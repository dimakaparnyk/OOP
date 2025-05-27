#include "Sport.h"
#include <iostream>
using namespace std;

// Реалізація конструктора для базового класу
Sport::Sport(string n, int p) : name(n), participants(p) {}

// Виведення загальної інформації про спорт
void Sport::displayInfo() {
    cout << "Sport: " << name << ", Participants: " << participants << endl;
}

// Реалізація методу start для базового класу
void Sport::start() {
    cout << "Starting " << name << " with " << participants << " participants." << endl;
}

Sport::~Sport() {}

// Реалізація конструктора для тренажерного залу
Gym::Gym(string n, int p, string e) : Sport(n, p), equipment(e) {}

// Виведення інформації про тренажерний зал
void Gym::displayInfo() {
    Sport::displayInfo();
    cout << "Equipment: " << equipment << endl;
}

// Реалізація методу start для тренажерного залу
void Gym::start() {
    cout << "Starting gym workout with " << equipment << "." << endl;
}

// Реалізація конструктора для футболу
Football::Football(string n, int p) : Sport(n, p) {}

// Виведення інформації про футбол
void Football::displayInfo() {
    Sport::displayInfo();
}

// Реалізація методу start для футболу
void Football::start() {
    cout << "Starting football game with " << participants << " players." << endl;
}

// Реалізація конструктора для баскетболу
Basketball::Basketball(string n, int p) : Sport(n, p) {}

// Виведення інформації про баскетбол
void Basketball::displayInfo() {
    Sport::displayInfo();
}

// Реалізація методу start для баскетболу
void Basketball::start() {
    cout << "Starting basketball game with " << participants << " players." << endl;
}

// Реалізація конструктора для плавання
Swimming::Swimming(string n, int p, string pool) : Sport(n, p), poolType(pool) {}

// Виведення інформації про плавання
void Swimming::displayInfo() {
    Sport::displayInfo();
    cout << "Pool Type: " << poolType << endl;
}

// Реалізація методу start для плавання
void Swimming::start() {
    cout << "Starting swimming in " << poolType << " pool with " << participants << " swimmers." << endl;
}