#include "LibraryFacade.h"
#include "LibraryLogger.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    LibraryFacade* library = new LibraryFacade();
    LibraryLogger* logger = LibraryLogger::getInstance();

    logger->log("Початок роботи бібліотеки...");
    int cost = library->processLibraryRequest("C++ Basics", true, false);
    if (cost > 0) {
        cout << "Вартість послуги: " << cost << endl;
        logger->log("Операція успішна, вартість: " + to_string(cost));
    }
    else {
        logger->log("Операція не вдалася.");
    }

    delete library;
    char c = getchar(); // Повернуто getchar()
    return 0;
}