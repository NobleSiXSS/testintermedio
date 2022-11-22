#include <iostream>

#ifndef DATE_H
#define DATE_H


class Date {
private:
    // Proprietà private
    int day_;
    int month_;
    int year_;

public:
    // Costruttore di default
    Date();
    
    // Costruttore che ha come argomenti tre interi: (ANNO, MESE, GIORNO)
    Date(int y, int m, int d);
    // Costruttore che ha come argomento una stringa in formato "ANNO/MESE/GIORNO"
    Date(const std::string& stringDate);

    // Funzione statica per controllare che una data sia corretta. Argomenti: (ANNO, MESE, GIORNO)
    static bool is_valid(int y, int m, int d);
    // Funzione statica per controllare che una data sia corretta. Argomenti: string "ANNO/MESE/GIORNO"
    static bool is_valid(const std::string& stringDate);

    // Funzioni getter
    int year() const;
    int month() const;
    int day() const;

};

// Overload operatore <<
std::ostream& operator<<(std::ostream& output, const Date& dateToPrint);

bool operator==(const Date &date1, const Date &date2);

bool operator!=(const Date &date1, const Date &date2);

#endif //DATE_H
