#include "date.h"
#include <iostream>
#include <vector>
#include <sstream>


std::vector<std::string> splitDate(const std::string& str) {
    // declaring temp string to store the curr "word" upto del
    std::string temp;
    int j = 0;
    std::vector<std::string> arr(3);

    for(char i : str) {
        // If cur char is not del, then append it to the cur "word", otherwise
        // you have completed the word, print it, and start a new word.
        if(i != '/'){
            temp += i;
        }
        else {
            arr[j] = temp;
            temp = "";
            j = j + 1;
        }
    }

    arr[j] = temp;

    return arr;
}

//costruttore
Date::Date(int y, int m, int d) {
    if(!is_valid(y, m, d)) {
        throw std::invalid_argument("Date format is not correct");
    }
    year_ = y;
    month_ = m;
    day_ = d;
}

Date::Date(std::string stringDate) {
    std::vector<std::string> arr = splitDate(stringDate);
    std::stringstream ssYear(arr[0]);
    std::stringstream ssMonth(arr[1]);
    std::stringstream ssDay(arr[2]);

    int y;
    int m;
    int d;

    ssYear >> y;
    ssMonth >> m;
    ssDay >> d;

    if(!is_valid(y, m, d)) {
        throw std::invalid_argument("Date format is not correct");
    }
    year_ = y;
    month_ = m;
    day_ = d;
}

    
//costruttore di default con una data standard: 1 gennaio 1970

Date::Date() : year_{1970}, month_{1}, day_{1} {

}

bool Date::is_valid(int y, int m, int d) {
    
    //controllo il mese e il giorno in modo generico
    if(m<1 || m>12 || d<1 || d>31){
        return false;
    }
    
    //controllo che l'anno sia bisestile e quindi febbraio deve avere meno di 29 giorni
    if((y%400 == 0 || (y%4 == 0 && y%100 != 0)) && (m == 2 && (d >= 1 && d <= 29))){
        return true;
    }
    //controllo che febbraio non abbia più di 28 giorni se non è bisestile
    else if(m == 2 && (d<1 || d>28)){
        return false;
    }
    else{    
        return true;
    }
}

int Date::year() const{
    return year_;
}

int Date::month() const{
    return month_;
}

int Date::day() const{
    return day_;
}


//overloading operatore <<
std::ostream& operator<<(std::ostream& output, const Date& dateToPrint) {
    return output << dateToPrint.year() << "/" << dateToPrint.month() << "/" << dateToPrint.day();
}