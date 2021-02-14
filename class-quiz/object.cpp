#include <string>

class C
{
private:
    int i;

    bool b;

    void f(int x);

public:
    C(int x) { i = x; }

    int j;

    std::string s = "ciao";

    void g(int x, int y) { std::cout << (x + y) << std::endl; }

    int h(std::string s);
};

int main()
{
    // Ex: scrivere risultato a video dell'esecuzione del codice
    // etichettato da 1 a 8, se possibile o "errore" nel caso
    // la riga generi un errore a compile time.

    C pippo;                                           // (1)
    C pluto(6);                                        // (2)
    std::cout << pippo.i << std::endl;                 // (3)
    std::cout << (pluto.b ? "SI" : "NO") << std::endl; // (4)
    pippo.f(pippo.j);                                  // (5)
    pluto.g(pippo.i, pluto.j);                         // (6)
    pluto.g(pippo.j, pluto.j);                         // (7)
    std::cout << pippo.g(pluto.s) << std::endl;        // (8)

    return 0;
}
