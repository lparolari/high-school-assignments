#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Libro {
   private:
    string _titolo;
    string _autore;
    int _anno;

   public:
    Libro(string titolo, string autore, int anno) {
        this->_titolo = titolo;
        this->_autore = autore;
        this->_anno = anno;
    }

    string titolo() {
        return _titolo;
    }

    string autore() {
        return _autore;
    }

    int anno() {
        return _anno;
    }

    string to_string() {
        return "" + titolo() + ", " + autore() + ", " + std::to_string(anno());
    }
};

class Biblioteca {
   private:
    vector<Libro> v;

   public:
    void aggiungi(Libro l) {
        v.push_back(l);
    }
    void vedi() {
        for (Libro l : v) {
            cout << l.to_string() << endl;
        }
    }
    void cerca(string autore) {
        for (Libro l : v) {
            if (l.autore().find(autore) != string::npos) {
                cout << l.to_string() << endl;
                return;
            }
        }
    }
};

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