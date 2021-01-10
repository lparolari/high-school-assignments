#include <iostream>
#include <string>

#include "albero.hpp"

int main()
{
    // Vogliamo costruire l'albero
    //           3
    //       1       2

    Albero::Albero *a11 = Albero::da_valore(1);
    Albero::Albero *a12 = Albero::da_valore(2);
    Albero::Albero *a1 = Albero::da_valore(3);

    Albero::Albero *a = Albero::unisci(a1, a11, a12);
    Albero::Albero *vuoto = Albero::da_vuoto();

    Albero::stampa(a);
    Albero::stampa(vuoto);

    // std::vector<int> dati = {9, 6, 2, 7, 8, 3, 11, 5, 4, 0, 1};
    // Albero::Albero *b = Albero::da_array(dati);

    // Albero::stampa(b);

    return 0;
}
