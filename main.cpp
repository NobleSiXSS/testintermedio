#include "date.h"
#include "book.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "TEST DELLA CLASSE DATE" << "\n";
    cout << "test anno bisestile" << "\n";
    Date d1{2012, 2, 29};
    cout << d1 << "\n";

    cout << " " << "\n";

    cout << "test anno generico" << "\n";
    Date d2{2022, 11, 18};
    //cout << d2.getYear() <<"\n"<< d2.getMonth() <<"\n"<< d2.getDay() <<"\n";
    cout << d2 << "\n";

    cout << "test costruttore di default della classe Date" << "\n";
    Date d3{};
    cout << d3 << "\n";

    cout << "TEST BOOK" << "\n";

    Book test("Test", "Test", "Test",  "999-555-141-a");

    Book test1("AAAA", "TAAAest", "TestBBBB",  "999-555-141-4");

    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");

    cout << test1 << "\n";

    bool a = test1 == test;

    cout << " " << "\n";

    if(a){
        cout << "i due codici ISBN sono uguali" <<"\n";
    }
    else{
        cout << "i due codici ISBN sono diversi" <<"\n";
    }

    //vedi commento sull'header di Book
    vector<Book> shelf(10);
    cout << shelf[1] << endl;
    return 0;
}
