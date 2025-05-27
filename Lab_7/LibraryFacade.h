#pragma once

#include <string>

class BookSearch {
public:
    virtual int findBook(const std::string& title) = 0;
    virtual ~BookSearch() {}
};

class BookIssue {
public:
    virtual int issueBook(int bookId) = 0;
    virtual ~BookIssue() {}
};

class BookReturn {
public:
    virtual int returnBook(int bookId) = 0;
    virtual ~BookReturn() {}
};

class LibraryFacade {
private:
    BookSearch* searchSystem;
    BookIssue* issueSystem;
    BookReturn* returnSystem;

public:
    LibraryFacade();
    int processLibraryRequest(const std::string& title, bool issue, bool returnBook);
    ~LibraryFacade();
};