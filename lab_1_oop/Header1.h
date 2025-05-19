#ifndef HEADER1_H
#define HEADER1_H

#include <iostream>
using namespace std;

struct Price {
    int hrn;
    short int kop;
};

void sum(Price& a, Price& b);
void mult(Price& a, int quantity);
void roundTo10(Price& p);
void print(Price& p);

#endif
#pragma once
