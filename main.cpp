#include <iostream>
#include <vector>
#include "book.h"
#include "date.h"

using namespace std;

int main() {
    Book test("Test", "Test", "Test",  "999-555-141-0");
    Book test1("AAAA", "TAAAest", "TestBBBB",  "999-555-141-a");
    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");
    bool a = test1 == test;
    cout << a << endl;
    cout << my_favourite_book << endl;

    std::vector<Book> shelf(10);
    shelf[1].setAuthorName("AAAA");
    cout << shelf[1] << endl;

    Date testDate{2011,2,28};
    cout << testDate << endl;
    return 0;
}
