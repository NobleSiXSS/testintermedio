//
// Created by Halo on 16/11/2022.
//
#include "iostream"
#ifndef TESTINTERMEDIO_DATE_H
#define TESTINTERMEDIO_DATE_H


class Date {
private:
    int d; // day
    int m; // month
    int y; // year

    bool is_valid();

public:
    class Invalid{};
    Date();

    Date(int year, int month, int day);
    int month() const;
    int day() const;
    int year() const;

    //int Day()
};

std::ostream& operator<<(std::ostream& output, const Date& dateObj);


#endif //TESTINTERMEDIO_DATE_H
