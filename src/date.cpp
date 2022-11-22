#include "../toinclude/date.h"
#include <iostream>
#include <vector>
#include <sstream>

// Funzione per dividere anno, mese e giorno da una stringa in formato "ANNO/MESE/GIORNO"
std::vector<int> splitDate(const std::string& str) {
    std::string temp;
    int j = 0;
    std::vector<int> arr(3);

    for(char i : str) {
        if(i != '/'){
            temp += i;
        }
        else {
            std::stringstream ss(temp);
            ss >> arr[j];
            temp = "";
            j = j + 1;
        }
    }

    std::stringstream ss(temp);
    ss >> arr[j];

    return arr;
}

// Costruttore che ha come argomenti tre interi: (ANNO, MESE, GIORNO)
Date::Date(int y, int m, int d) {
    // Se is_valid() restituisce false lancio un errore
    if(!is_valid(y, m, d)) {
        throw std::invalid_argument("Date format is not correct");
    }
    // Modifico le proprietà dell'oggetto
    year_ = y;
    month_ = m;
    day_ = d;
}

// Costruttore che ha come argomento una stringa in formato "ANNO/MESE/GIORNO"
Date::Date(const std::string& stringDate) {
    // Ricevo dalla funzione splitDate un array di 3 elementi interi: [ANNO, MESE, GIORNO]
    std::vector<int> arr = splitDate(stringDate);

    // Se is_valid() restituisce false lancio un errore
    if(!is_valid(arr[0], arr[1], arr[2])) {
        throw std::invalid_argument("Date format is not correct");
    }

    // Modifico le proprietà dell'oggetto
    year_ = arr[0];
    month_ = arr[1];
    day_ = arr[2];
}

    
//costruttore di default con una data standard: 1 gennaio 1970
Date::Date() : year_{1970}, month_{1}, day_{1} { }

// Funzione che controlla se una data è valida, considerando anche gli anni bisestili
bool Date::is_valid(int y, int m, int d) {
    
    //controllo il mese e il giorno in modo generico
    if(m<1 || m>12 || d<1 || d>31){
        return false;
    }
    
    //controllo che l'anno sia bisestile e quindi febbraio deve avere meno di 29 giorni
    if((y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) && (m == 2 && d <= 29)) {
        return true;
    }
    //controllo che febbraio non abbia più di 28 giorni se non è bisestile
    else if(m == 2 && d > 28){
        return false;
    }
    else{    
        return true;
    }
}

// Funzione che controlla se una data è valida, considerando anche gli anni bisestili
bool Date::is_valid(const std::string &stringDate) {
    std::vector<int> arr = splitDate(stringDate);
    return is_valid(arr[0], arr[1], arr[2]);
}

// Funzioni getter

int Date::year() const{
    return year_;
}

int Date::month() const{
    return month_;
}

int Date::day() const{
    return day_;
}

// Funzioni setter
void Date::set_day(int day) {
    if(!is_valid(year_, month_, day)) {
        throw std::invalid_argument("Date format is not correct");
    }
    day_ = day;
}

void Date::set_month(int month) {
    if(!is_valid(year_, month, day_)) {
        throw std::invalid_argument("Date format is not correct");
    }
    month_ = month;
}

void Date::set_year(int year) {
    if(!is_valid(year, month_, day_)) {
        throw std::invalid_argument("Date format is not correct");
    }
    year_ = year;
}

void Date::set_date(int y, int m, int d) {
    // Se is_valid() restituisce false lancio un errore
    if(!is_valid(y, m, d)) {
        throw std::invalid_argument("Date format is not correct");
    }
    // Modifico le proprietà dell'oggetto
    year_ = y;
    month_ = m;
    day_ = d;
}

void Date::set_date(const std::string& stringDate) {
    // Ricevo dalla funzione splitDate un array di 3 elementi interi: [ANNO, MESE, GIORNO]
    std::vector<int> arr = splitDate(stringDate);

    // Se is_valid() restituisce false lancio un errore
    if(!is_valid(arr[0], arr[1], arr[2])) {
        throw std::invalid_argument("Date format is not correct");
    }

    // Modifico le proprietà dell'oggetto
    year_ = arr[0];
    month_ = arr[1];
    day_ = arr[2];
}

void Date::set_date() {
    year_ = 1970;
    month_ = 1;
    day_ = 1;
}

bool operator==(const Date &date1, const Date &date2) {
    return date1.day() == date2.day() &&
           date1.month() == date2.month() &&
           date1.year() == date2.year();
}

bool operator!=(const Date &date1, const Date &date2) {
    return !(date1 == date2);
}

//overloading operatore <<, allo stream viene inviata la stringa "ANNO/MESE/GIORNO"
std::ostream& operator<<(std::ostream& output, const Date& dateToPrint) {
    return output << dateToPrint.year() << "/" << dateToPrint.month() << "/" << dateToPrint.day();
}