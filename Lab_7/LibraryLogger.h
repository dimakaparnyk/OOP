#pragma once

#include <string>

class LibraryLogger {
private:
    LibraryLogger() {}
    static LibraryLogger* instance;

public:
    static LibraryLogger* getInstance();
    void log(const std::string& message);
};