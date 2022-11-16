//
// Created by Halo on 16/11/2022.
//

#include "book.h"
//#include "date.h"
#include "iostream"


/*Book::Book(string& authorName, string& authorSurname, string& title, Date& copyrightDate, string& ISBN) {
    this->authorName = authorName;
    this->authorSurname = authorSurname;
    this->title = title;
    //this->copyrightDate = copyrightDate;
    this->ISBN = ISBN;
    this->available = true;
}*/

Book::Book(std::string authorName, std::string authorSurname, std::string title, std::string ISBN) {
    if(!isValidISBN(ISBN)) {
        throw std::invalid_argument("ISBN format is not correct. NNN-NNN-NNN-C");
    }
    this->authorName = authorName;
    this->authorSurname = authorSurname;
    this->title = title;
    this->ISBN = ISBN;
    this->available = true;
}

std::string Book::getISBN() const {
    return this->ISBN;
}
std::string Book::getTitle() const {
    return this->title;
}
std::string Book::getAuthor() const {
    return this->authorName + " " + authorSurname;
}
std::string Book::getAuthorName() const {
    return this->authorName;
}
std::string Book::getAuthorSurname() const {
    return this->authorSurname;
}
bool Book::isAvailable() const {
    return this->available;
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
    this->available = isAvailable;
}

/*Date Book::getCopyrightDate() const {
    return Date();
}*/

std::ostream& operator<<(std::ostream& output, const Book& bookObj) {
    return output << bookObj.getTitle() << std::endl << bookObj.getAuthor() << std::endl << bookObj.getISBN() << std::endl; //<< bookObj.getCopyrightDate();
}

bool operator==(const Book& bookLeft, const Book& bookRight) {
    return bookLeft.getISBN() == bookRight.getISBN();
}

bool operator!=(const Book& bookLeft, const Book& bookRight) {
    return bookLeft.getISBN() != bookRight.getISBN();
}
