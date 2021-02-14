#include <iostream>

class C
{
public:
    int i = 0;

    C()
    {
        this->i = 150;
    }
};

int main()
{
    // Ex: scrivere risultato a video dell'esecuzione del codice
    // etichettato da 1 a 8, se possibile o "errore" nel caso
    // la riga generi un errore a compile time.

    C pippo;
    C pluto;

    pippo.i = 5;
    pluto.i = 10;

    std::cout << pippo.i << std::endl; // (1)
    std::cout << pluto.i << std::endl; // (2)
}
