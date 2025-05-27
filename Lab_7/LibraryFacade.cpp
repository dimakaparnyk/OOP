#include "LibraryFacade.h"
#include <iostream>

using namespace std;

class ConcreteBookSearch : public BookSearch {
public:
    int findBook(const string& title) override {
        cout << "Searching for book: " << title << endl;
        return (title == "C++ Basics") ? 1 : -1;
    }
};

class ConcreteBookIssue : public BookIssue {
public:
    int issueBook(int bookId) override {
        cout << "Issuing book with ID: " << bookId << endl;
        return (bookId > 0) ? 15 : 0;
    }
};

class ConcreteBookReturn : public BookReturn {
public:
    int returnBook(int bookId) override {
        cout << "Returning book with ID: " << bookId << endl;
        return (bookId > 0) ? 5 : 0;
    }
};

LibraryFacade::LibraryFacade() {
    searchSystem = new ConcreteBookSearch();
    issueSystem = new ConcreteBookIssue();
    returnSystem = new ConcreteBookReturn();
}

int LibraryFacade::processLibraryRequest(const string& title, bool issue, bool returnBook) {
    int bookId = searchSystem->findBook(title);
    int cost = 0;
    if (bookId > 0) {
        if (issue) {
            cost += issueSystem->issueBook(bookId);
        }
        if (returnBook) {
            cost += returnSystem->returnBook(bookId);
        }
        return cost;
    }
    return -1;
}

LibraryFacade::~LibraryFacade() {
    delete searchSystem;
    delete issueSystem;
    delete returnSystem;
}