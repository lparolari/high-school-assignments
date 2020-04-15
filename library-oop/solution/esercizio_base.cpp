#include <iostream>
#include <string>
#include <vector>

using namespace std;

// class Libro
// DA FARE

// class Biblioteca
// DA FARE

int main() {
    Libro l1("C++. Linguaggio, libreria standard, principi di programmazione", "Bjarne Stroustrup", 2015);
    Libro l2("Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin", 2008);
    Libro l3("Programming in Haskell", "Graham Hutton", 2016);

    Biblioteca b;

    b.aggiungi(l1);
    b.aggiungi(l2);
    b.aggiungi(l3);

    cout << "BIBLIOTECA" << endl;
    b.vedi();
    cout << endl;

    cout << "CERCA UN LIBRO" << endl;
    b.cerca("Graham");
    b.cerca("o");
    b.cerca("Pippo");

    return 0;
}

/* **************************************
   OUTPUT
   **************************************

BIBLIOTECA
C++. Linguaggio, libreria standard, principi di programmazione, Bjarne Stroustrup, 2015
Clean Code: A Handbook of Agile Software Craftsmanship, Robert C. Martin, 2008
Programming in Haskell, Graham Hutton, 2016

CERCA UN LIBRO
Programming in Haskell, Graham Hutton, 2016
C++. Linguaggio, libreria standard, principi di programmazione, Bjarne Stroustrup, 2015

*/