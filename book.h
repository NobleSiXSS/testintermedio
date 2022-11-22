//
// Created by Halo on 16/11/2022.
//

#include <iostream>
#include "date.h"
#ifndef BOOK_H
#define BOOK_H

class Book {
private:
    // Proprietà
    std::string ISBN_;
    std::string title_;
    std::string authorName_;
    std::string authorSurname_;
    bool available_;
    Date copyrightDate_;

public:
    // Costruttori

    // Costruttore che accetta in input tutti i dati tranne la data di copyright (come da esempio nel pdf)
    Book(std::string authorName, std::string authorSurname, std::string title, std::string ISBN);
    // Costruttore che accetta un oggetto di tipo Date per la data di copyright
    Book(std::string authorName, std::string authorSurname, std::string title, Date copyrightDate, std::string ISBN);
    // Costruttore che accetta una stringa in formato "ANNO/MESE/GIORNO" per la data di copyright
    Book(std::string authorName, std::string authorSurname, std::string title, std::string copyrightDate, std::string ISBN);
    // Costruttore di default
    Book();

    // Funzione statica che permette di controllare che un codice ISBN sia valido, esempio -> Book::isValidISBN("887-521-837-4")
    static bool isValidISBN(const std::string& ISBNToCheck);

    // Funzioni getter
    std::string ISBN() const;
    std::string title() const;
    std::string authorName() const;
    std::string authorSurname() const;
    std::string author() const;
    bool available() const;
    Date copyrightDate() const;

    // Funzioni setter
    void setAvailability(bool isAvailable);
    void setIsbn(const std::string &isbn);
    void setTitle(const std::string &title);
    void setAuthorName(const std::string &authorName);
    void setAuthorSurname(const std::string &authorSurname);
    void setAvailable(bool available);
    void setCopyrightDate(const Date &copyrightDate);
    void setCopyrightDate(const std::string &copyrightDate);
};

// Overload operatori
std::ostream& operator<<(std::ostream& output, const Book& bookObj);
bool operator==(const Book& bookLeft, const Book& bookRight);
bool operator!=(const Book& bookLeft, const Book& bookRight);


#endif //BOOK_H