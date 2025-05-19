#include "Sport.h"
#include <iostream>
using namespace std;

// Реалізація PhysicalActivity
PhysicalActivity::PhysicalActivity(string t) : type(t) {
    cout << "Конструктор PhysicalActivity викликаний для " << type << endl;
}

void PhysicalActivity::displayInfo() {
    cout << "Тип фізичної активності: " << type << endl;
}

PhysicalActivity::~PhysicalActivity() {
    cout << "Деструктор PhysicalActivity викликаний для " << type << endl;
}

// Реалізація Sport
Sport::Sport(string t, string n, int p) : PhysicalActivity(t), name(n), participants(p) {
    cout << "Конструктор Sport викликаний для " << name << endl;
}

void Sport::displayInfo() {
    PhysicalActivity::displayInfo();
    cout << "Спорт: " << name << ", Учасників: " << participants << endl;
}

Sport::~Sport() {
    cout << "Деструктор Sport викликаний для " << name << endl;
}

// Реалізація TeamSport
TeamSport::TeamSport(string t, string n, int p, int tm) : PhysicalActivity(t), Sport(t, n, p), teams(tm) {
    cout << "Конструктор TeamSport викликаний для " << name << endl;
}

void TeamSport::displayInfo() {
    Sport::displayInfo();
    cout << "Команд: " << teams << endl;
}

TeamSport::~TeamSport() {
    cout << "Деструктор TeamSport викликаний для " << name << endl;
}

// Реалізація EquipmentSport
EquipmentSport::EquipmentSport(string t, string n, int p, string e) : PhysicalActivity(t), Sport(t, n, p), equipment(e) {
    cout << "Конструктор EquipmentSport викликаний для " << name << endl;
}

void EquipmentSport::displayInfo() {
    Sport::displayInfo();
    cout << "Обладнання: " << equipment << endl;
}

EquipmentSport::~EquipmentSport() {
    cout << "Деструктор EquipmentSport викликаний для " << name << endl;
}

// Реалізація Gym
Gym::Gym(string n, int p, string e) : PhysicalActivity("Indoor"), Sport("Indoor", n, p), EquipmentSport("Indoor", n, p, e) {
    cout << "Конструктор Gym викликаний для " << name << endl;
}

void Gym::displayInfo() {
    EquipmentSport::displayInfo();
}

void Gym::start() {
    cout << "Починаємо тренування в тренажерному залі з " << equipment << endl;
}

Gym::~Gym() {
    cout << "Деструктор Gym викликаний для " << name << endl;
}

// Реалізація Football
Football::Football(string n, int p) : PhysicalActivity("Outdoor"), Sport("Outdoor", n, p), TeamSport("Outdoor", n, p, 2) {
    cout << "Конструктор Football викликаний для " << name << endl;
}

void Football::displayInfo() {
    TeamSport::displayInfo();
}

void Football::start() {
    cout << "Починаємо футбольний матч!" << endl;
}

Football::~Football() {
    cout << "Деструктор Football викликаний для " << name << endl;
}

// Реалізація Basketball - приклад множинного успадкування
Basketball::Basketball(string n, int p)
    : PhysicalActivity("Indoor/Outdoor"),
    Sport("Indoor/Outdoor", n, p),
    TeamSport("Indoor/Outdoor", n, p, 2),
    EquipmentSport("Indoor/Outdoor", n, p, "Баскетбольний м'яч") {
    cout << "Конструктор Basketball викликаний для " << name << endl;
}

void Basketball::displayInfo() {
    TeamSport::displayInfo();
    cout << "Обладнання: " << equipment << endl;
}

void Basketball::start() {
    cout << "Починаємо баскетбольний матч з " << equipment << "!" << endl;
}

Basketball::~Basketball() {
    cout << "Деструктор Basketball викликаний для " << name << endl;
}

// Реалізація Swimming
Swimming::Swimming(string n, int p, string pool) : PhysicalActivity("Water"), Sport("Water", n, p), poolType(pool) {
    cout << "Конструктор Swimming викликаний для " << name << endl;
}

void Swimming::displayInfo() {
    Sport::displayInfo();
    cout << "Тип басейну: " << poolType << endl;
}

void Swimming::start() {
    cout << "Починаємо плавання в басейні " << poolType << "!" << endl;
}

Swimming::~Swimming() {
    cout << "Деструктор Swimming викликаний для " << name << endl;
}

// Реалізація Triathlon
Triathlon::Triathlon(string n, int p, string pool, string e)
    : PhysicalActivity("Mixed"),
    Sport("Mixed", n, p),
    Swimming(n, p, pool),
    Gym(n, p, e),
    TeamSport("Mixed", n, p, 1) {
    cout << "Конструктор Triathlon викликаний для " << Sport::name << endl;
}

void Triathlon::displayInfo() {
    cout << "----- Інформація про триатлон -----" << endl;
    PhysicalActivity::displayInfo();
    cout << "Спорт: " << Sport::name << ", Учасників: " << Sport::participants << endl;
    cout << "Тип басейну: Плавання в " << poolType << endl;
    cout << "Обладнання: Використовуємо " << equipment << endl;
    cout << "Командний: " << (teams == 1 ? "Індивідуальний спорт" : "Командний спорт") << endl;
}

void Triathlon::start() {
    cout << "Починаємо змагання з триатлону!" << endl;
    cout << "1. Етап плавання" << endl;
    cout << "2. Етап велоспорту з " << equipment << endl;
    cout << "3. Етап бігу" << endl;
}

Triathlon::~Triathlon() {
    cout << "Деструктор Triathlon викликаний для " << Sport::name << endl;
}
