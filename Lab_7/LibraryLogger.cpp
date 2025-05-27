#include "LibraryLogger.h"
#include <iostream>

using namespace std;

LibraryLogger* LibraryLogger::instance = nullptr;

LibraryLogger* LibraryLogger::getInstance() {
    if (!instance) {
        instance = new LibraryLogger();
    }
    return instance;
}

void LibraryLogger::log(const string& message) {
    cout << "ЗАПИС: " << message << endl;
}