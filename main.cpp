#include <iostream>
#include "book.h"
using namespace std;

int main() {
    Book test("Test", "Test", "Test",  "999-555-141-a");
    Book test1("AAAA", "TAAAest", "TestBBBB",  "999-555-141-!");
    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");
    bool a = test1 == test;
    cout << a;
    return 0;
}
