//
// Created by Halo on 16/11/2022.
//

#include <iostream>
#include "date.h"
#ifndef TESTINTERMEDIO_BOOK_H
#define TESTINTERMEDIO_BOOK_H

class Book {
private:
    std::string ISBN_;
    std::string title_;
    std::string authorName_;
    std::string authorSurname_;
    bool available_;
    Date copyrightDate_;

public:
    //Book(std::string &authorName, std::string &authorSurname, std::string &title, Date &copyrightDate, std::string &ISBN);
    Book(std::string authorName, std::string authorSurname, std::string title, std::string ISBN);
    Book(std::string authorName, std::string authorSurname, std::string title, Date copyrightDate, std::string ISBN);
    Book(std::string authorName, std::string authorSurname, std::string title, std::string copyrightDate, std::string ISBN);
    Book();

    static bool isValidISBN(std::string& ISBNToCheck);

    std::string ISBN() const;
    std::string title() const;
    std::string authorName() const;
    std::string authorSurname() const;
    std::string author() const;
    bool available() const;
    void setAvailability(bool isAvailable);

    void setIsbn(const std::string &isbn);

    void setTitle(const std::string &title);

    void setAuthorName(const std::string &authorName);

    void setAuthorSurname(const std::string &authorSurname);

    void setAvailable(bool available);

    void setCopyrightDate(const Date &copyrightDate);

    Date copyrightDate() const;
};

std::ostream& operator<<(std::ostream& output, const Book& bookObj);
bool operator==(const Book& bookLeft, const Book& bookRight);
bool operator!=(const Book& bookLeft, const Book& bookRight);


#endif //TESTINTERMEDIO_BOOK_H