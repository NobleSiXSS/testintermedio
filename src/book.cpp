#include "../toinclude/book.h"
#include "../toinclude/date.h"
#include "iostream"

// Costruttori
Book::Book() {
    this->available_ = true;
};


Book::Book(std::string authorName, std::string authorSurname, std::string title, std::string copyrightDate, std::string ISBN) {
    // se isValidISBN restituisce false lancio un errore
    if(!isValidISBN(ISBN)) {
        throw std::invalid_argument("ISBN format is not correct. NNN-NNN-NNN-C");
    }
    this->author_surname_ = authorName;
    this->author_name_ = authorSurname;
    this->title_ = title;
    this->copyright_date_ = Date(copyrightDate);
    this->ISBN_ = ISBN;
    this->available_ = true;
}

Book::Book(std::string authorName, std::string authorSurname, std::string title, Date copyrightDate, std::string ISBN) {
    // se isValidISBN restituisce false lancio un errore
    if(!isValidISBN(ISBN)) {
        throw std::invalid_argument("ISBN format is not correct. NNN-NNN-NNN-C");
    }
    this->author_surname_ = authorName;
    this->author_name_ = authorSurname;
    this->title_ = title;
    this->copyright_date_ = copyrightDate;
    this->ISBN_ = ISBN;
    this->available_ = true;
}

Book::Book(std::string authorName, std::string authorSurname, std::string title, std::string ISBN) {
    // se isValidISBN restituisce false lancio un errore
    if(!isValidISBN(ISBN)) {
        throw std::invalid_argument("ISBN format is not correct. NNN-NNN-NNN-C");
    }
    this->author_surname_ = authorName;
    this->author_name_ = authorSurname;
    this->title_ = title;
    this->ISBN_ = ISBN;
    this->available_ = true;
}

// Funzioni getter
std::string Book::ISBN() const {
    return this->ISBN_;
}
std::string Book::title() const {
    return this->title_;
}
std::string Book::author() const {
    return this->author_surname_ + " " + author_name_;
}
std::string Book::author_name() const {
    return this->author_surname_;
}
std::string Book::author_surname() const {
    return this->author_name_;
}

Date Book::copyright_date() const {
    return this->copyright_date_;
}

bool Book::available() const {
    return this->available_;
}
// Funzione statica che permette di controllare che un codice ISBN sia valido, esempio -> isValidISBN("887-521-837-4")
bool Book::isValidISBN(const std::string& ISBNToCheck) {

    // Controllo che la lunghezza dell'ISBN sia di 13 caratteri e che le 4 parti dell'ISBN siano divise dal carattere '-', in caso contrario ritorno false
    if(ISBNToCheck.length() != 13 || ISBNToCheck[3] != '-' || ISBNToCheck[7] != '-' || ISBNToCheck[11] != '-') {
        return false;
    }

    // Controllo che l'ultimo carattere sia una lettera o un numero, in caso contrario ritorno false
    if(!((ISBNToCheck[12] >= 65 && ISBNToCheck[12] <= 90) || (ISBNToCheck[12] >= 97 && ISBNToCheck[12] <= 122) || (ISBNToCheck[12] >= 48 && ISBNToCheck[12] <= 57))) {
        return false;
    }

    // Controllo che le prime 3 parti NNN dell'ISBN siano formate esclusivamente da numeri, in caso contrario restituisco false
    int i;
    for(i = 0; i < 3; i++) {
        if(!(ISBNToCheck[i] >= 48 && ISBNToCheck[i] <= 57)) {
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

    // Se l'esecuzione è arrivata a questo punto significa che l'ISBN è nel formato corretto, quindi restituisco true
    return true;
}

// Funzioni setter
void Book::set_available(bool isAvailable) {
    this->available_ = isAvailable;
}

void Book::set_ISBN(const std::string &isbn) {
    if(!isValidISBN(isbn)) {
        throw std::invalid_argument("ISBN format is not correct. NNN-NNN-NNN-C");
    }
    this->ISBN_ = isbn;
}

void Book::set_title(const std::string &title) {
    this->title_ = title;
}

void Book::set_author_name(const std::string &authorName) {
    this->author_surname_ = authorName;
}

void Book::set_author_surname(const std::string &authorSurname) {
    this->author_name_ = authorSurname;
}

void Book::set_copyright_date(const Date &copyrightDate) {
    this->copyright_date_ = copyrightDate;
}

void Book::set_copyright_date(const std::string &copyrightDate) {
    this->copyright_date_ = Date{copyrightDate};
}

// Overload operatore <<
std::ostream& operator<<(std::ostream& output, const Book& bookObj) {
    //return output << bookObj.title() << std::endl << bookObj.author() << std::endl << bookObj.ISBN() << std::endl << bookObj.copyright_date();
    return output << "Titolo: "<<bookObj.title() << std::endl << "Autore: " << bookObj.author() << std::endl << "Codice ISBN: "<< bookObj.ISBN() << std::endl << "Data di Copyright: "<<bookObj.copyright_date();
}

// Overload operatore ==, confronto i due ISBN dei due oggetti di tipo Book
bool operator==(const Book& bookLeft, const Book& bookRight) {
    return bookLeft.ISBN() == bookRight.ISBN();
}

// Overload operatore !=, confronto i due ISBN dei due oggetti di tipo Book
bool operator!=(const Book& bookLeft, const Book& bookRight) {
    return bookLeft.ISBN() != bookRight.ISBN();
}
