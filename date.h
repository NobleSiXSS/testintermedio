#include <iostream>

#ifndef TESTINTERMEDIO_DATE_H
#define TESTINTERMEDIO_DATE_H


class Date {
private:
    int day_{};
    int month_{};
    int year_{};
    static bool is_valid(int y, int m, int d);
    //std::vector<std::string> split(string str, char del);

public:
    
    //costruttore di default
    Date();
    
    //costruttore
    Date(int y, int m, int d);
    Date(std::string date);
    
    int year() const;
    int month() const;
    int day() const;
    
};

std::ostream& operator<<(std::ostream& output, const Date& dateToPrint);

#endif //TESTINTERMEDIO_DATE_H
