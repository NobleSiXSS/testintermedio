//
// Created by Halo on 16/11/2022.
//

#include <iostream>
//#include "date.h"

#ifndef TESTINTERMEDIO_BOOK_H
#define TESTINTERMEDIO_BOOK_H

class Book {
private:
    std::string ISBN;
    std::string title;
    std::string authorName;
    std::string authorSurname;
    bool available;
    //Date copyrightDate;

    static bool isValidISBN(std::string& ISBNToCheck);

public:
    //Book(std::string &authorName, std::string &authorSurname, std::string &title, Date &copyrightDate, std::string &ISBN);
    Book(std::string authorName, std::string authorSurname, std::string title, std::string ISBN);


    std::string getISBN() const;
    std::string getTitle() const;
    std::string getAuthorName() const;
    std::string getAuthorSurname() const;
    std::string getAuthor() const;
    bool isAvailable() const;
    void setAvailability(bool isAvailable);
   // Date getCopyrightDate() const;
};

std::ostream& operator<<(std::ostream& output, const Book& bookObj);
bool operator==(const Book& bookLeft, const Book& bookRight);
bool operator!=(const Book& bookLeft, const Book& bookRight);


#endif //TESTINTERMEDIO_BOOK_H