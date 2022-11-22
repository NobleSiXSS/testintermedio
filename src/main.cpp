#include "../toinclude/date.h"
#include "../toinclude/book.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "TEST DELLA CLASSE DATE" << "\n";
    cout << "test anno bisestile" << "\n";
    Date d1{2012, 2, 29};
    cout << d1 << "\n";
    d1.set_date("1954/5/30");
    cout << d1 << "\n";

    cout << "test anno generico" << "\n";
    Date d2{2022, 11, 18};
    //cout << d2.getYear() <<"\n"<< d2.getMonth() <<"\n"<< d2.getDay() <<"\n";
    cout << d2 << "\n";

    cout << "test costruttore di default della classe Date" << "\n";
    Date d3{};
    cout << d3 << "\n";

    cout << "test costruttore che accetta una data come stringa" << "\n";
    Date d4("2020/5/24");
    cout << d4 << "\n";

    cout << " " << "\n";

    cout << "TEST BOOK" << "\n";

    Book test("Test", "Test", "Test",  "999-555-141-a");

    Book test1("AAAA", "TAAAest", "TestBBBB",  "999-555-141-4");

    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4");

    cout << test << "\n";
    cout << test1 << "\n";

    bool a = test1 == test;

    cout << " " << "\n";

    if(a){
        cout << "i due codici ISBN sono uguali" <<"\n";
    }
    else{
        cout << "i due codici ISBN sono diversi" <<"\n";
    }

    cout << my_favourite_book << "\n";

    vector<Book> shelf(10);
    //cout << shelf[1] << endl;

    cout << " " << "\n";
    cout << " " << "\n";

    cout << "TEST DELLE FUNZIONI SET" << "\n";
    Book libro;

    libro.set_author_name("George");

    libro.set_author_surname("Orwell");

    libro.set_title("La fattoria degli animali");

    Date publicationDay{1945,8,17};

    libro.set_copyright_date(publicationDay);

    libro.set_ISBN("978-015-107-2");

    bool available=true;
    libro.set_available(available);

    cout << libro << "\n";

    if(available){
        cout << "Il libro e' disponibile " << "\n";
    }
    else {
        cout << "Il libro NON e' disponibile " << "\n";
    }

    cout << " " << "\n";

    Book libro2;
    libro2.set_author_name("Alexandre");

    libro2.set_author_surname("Dumas");

    libro2.set_title("I tre moschettieri");

    Date publication{1844,7,14};

    libro2.set_copyright_date(publication);

    libro2.set_ISBN("978-076-416-0");

    bool available2=false;
    libro.set_available(available2);

    cout << libro2 << "\n";

    if(available2){
        cout << "Il libro e' disponibile " << "\n";
    }
    else{
        cout << "Il libro NON e' disponibile " << "\n";
    }

    bool sameIsbn = test1 == test;

    if(sameIsbn){
        cout << "i due codici ISBN sono uguali" <<"\n";
    }
    else{
        cout << "i due codici ISBN sono diversi" <<"\n";
    }


    return 0;
}
