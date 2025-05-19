#include "Header1.h"
#include <fstream>
using namespace std;

void sum(Price& a, Price& b) {
    a.hrn += b.hrn;
    a.kop += b.kop;

    if (a.kop >= 100) {
        a.hrn += a.kop / 100;
        a.kop = a.kop % 100;
    }
}

void mult(Price& a, int quantity) {
    int totalKop = (a.hrn * 100 + a.kop) * quantity;
    a.hrn = totalKop / 100;
    a.kop = totalKop % 100;
}

void roundTo10(Price& p) {
    if (p.kop % 10 >= 5) {
        p.kop = (p.kop / 10) * 10 + 10;
    }
    else {
        p.kop = (p.kop / 10) * 10;
    }

    if (p.kop >= 100) {
        p.hrn += 1;
        p.kop -= 100;
    }
}

void print(Price& p) {
    cout << p.hrn << " uah " << p.kop << " cent." << endl;
}
