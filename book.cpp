//
// Created by Halo on 16/11/2022.
//

#include "book.h"
#include "date.h"
#include "iostream"

Book::Book() : available_{} {};

Book::Book(std::string authorName, std::string authorSurname, std::string title, std::string copyrightDate, std::string ISBN) {
    if(!isValidISBN(ISBN)) {
        throw std::invalid_argument("ISBN format is not correct. NNN-NNN-NNN-C");
    }
    this->authorName_ = authorName;
    this->authorSurname_ = authorSurname;
    this->title_ = title;
    this->copyrightDate_ = Date(copyrightDate);
    this->ISBN_ = ISBN;
    this->available_ = true;
}

Book::Book(std::string authorName, std::string authorSurname, std::string title, Date copyrightDate, std::string ISBN) {
   if(!isValidISBN(ISBN)) {
        throw std::invalid_argument("ISBN format is not correct. NNN-NNN-NNN-C");
    }
    this->authorName_ = authorName;
    this->authorSurname_ = authorSurname;
    this->title_ = title;
    this->copyrightDate_ = copyrightDate;
    this->ISBN_ = ISBN;
    this->available_ = true;
}

Book::Book(std::string authorName, std::string authorSurname, std::string title, std::string ISBN) {
    if(!isValidISBN(ISBN)) {
        throw std::invalid_argument("ISBN format is not correct. NNN-NNN-NNN-C");
    }
    this->authorName_ = authorName;
    this->authorSurname_ = authorSurname;
    this->title_ = title;
    this->ISBN_ = ISBN;
    this->available_ = true;
}

std::string Book::ISBN() const {
    return this->ISBN_;
}
std::string Book::title() const {
    return this->title_;
}
std::string Book::author() const {
    return this->authorName_ + " " + authorSurname_;
}
std::string Book::authorName() const {
    return this->authorName_;
}
std::string Book::authorSurname() const {
    return this->authorSurname_;
}

Date Book::copyrightDate() const {
    return this->copyrightDate_;
}

bool Book::available() const {
    return this->available_;
}

bool Book::isValidISBN(std::string& ISBNToCheck) {

    if(ISBNToCheck.length() != 13 || ISBNToCheck[3] != '-' || ISBNToCheck[7] != '-' || ISBNToCheck[11] != '-') {
        return false;
    }

    if(!((ISBNToCheck[12] >= 65 && ISBNToCheck[12] <= 90) || (ISBNToCheck[12] >= 97 && ISBNToCheck[12] <= 122) || (ISBNToCheck[12] >= 48 && ISBNToCheck[12]))) {
        return false;
    }

    int i;
    for(i = 0; i < 3; i++) {
        if(!(int(ISBNToCheck[i]) >= 48 && int(ISBNToCheck[i]) <= 57)) {
            return false;
        }
    }
    for(i = 4; i < 7; i++) {
        if(!(ISBNToCheck[i] >= 48 && ISBNToCheck[i] <= 57)) {
            return false;
        }
    }
    for(i = 8; i < 11; i++) {
        if(!(ISBNToCheck[i] >= 48 && ISBNToCheck[i] <= 57)) {
            return false;
        }
    }

    return true;
}

void Book::setAvailability(bool isAvailable) {
    this->available_ = isAvailable;
}

void Book::setIsbn(const std::string &isbn) {
    this->ISBN_ = isbn;
}

void Book::setTitle(const std::string &title) {
    this->title_ = title;
}

void Book::setAuthorName(const std::string &authorName) {
    this->authorName_ = authorName;
}

void Book::setAuthorSurname(const std::string &authorSurname) {
    this->authorSurname_ = authorSurname;
}

void Book::setAvailable(bool available) {
    this->available_ = available;
}

void Book::setCopyrightDate(const Date &copyrightDate) {
    this->copyrightDate_ = copyrightDate;
}

void Book::setCopyrightDate(const std::string &copyrightDate) {
    this->copyrightDate_ = Date(copyrightDate);
}

std::ostream& operator<<(std::ostream& output, const Book& bookObj) {
    return output << bookObj.title() << std::endl << bookObj.author() << std::endl << bookObj.ISBN() << std::endl << bookObj.copyrightDate();
}

bool operator==(const Book& bookLeft, const Book& bookRight) {
    return bookLeft.ISBN() == bookRight.ISBN();
}

bool operator!=(const Book& bookLeft, const Book& bookRight) {
    return bookLeft.ISBN() != bookRight.ISBN();
}
