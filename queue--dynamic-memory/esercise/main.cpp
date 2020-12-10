#include <iostream>
#include "coda.hpp"

int main()
{
    Coda::Coda c1 = Coda::costruisci_vuota(); // fila alla cassa 1
    Coda::Coda c2 = Coda::costruisci_vuota(); // fila alla cassa 2

    c1 = Coda::inserisci(c1, 1); // arriva il cliente 1 e va alla cassa 1
    c2 = Coda::inserisci(c2, 2); // arriva il cliente 2 e va alla cassa 2
    c1 = Coda::inserisci(c1, 3); // arriva il cliente 3 e va alla cassa 1

    std::cout << Coda::dimensione(c1) << std::endl; // restituisce 2
    std::cout << Coda::dimensione(c2) << std::endl; // restituisce 1

    std::cout << Nodo::valore(Coda::primo(c1)) << std::endl; // restituisce 1 (il cliente 1)

    Coda::stampa(c1); // stampa [1, 3, ]
    Coda::stampa(c2); // stampa [2, ]

    c1 = Coda::togli(c1); // viene servito il cliente 1 della cassa 1
    c2 = Coda::togli(c2); // viene servito il cliente 2 della cassa 2

    Coda::stampa(c1); // stampa [3, ] che sono i clienti ancora in attesa alla cassa 1
    Coda::stampa(c2); // stampa [] che sono i clienti ancora in attesa alla cassa 2(nessuno !)

    // Visualizza il primo cliente della cassa c2 (se esiste!)
    if (!Coda::is_vuota(c2))
    {
        std::cout << Coda::primo(c2) << std::endl;
    }
    else
    {
        std::cout << "La lista e' vuota!" << std::endl;
    }

    c1 = Coda::inserisci(c1, 4); // arriva il cliente 4 e va alla cassa 1
    c2 = Coda::inserisci(c2, 5); // arriva il cliente 5 e va alla cassa 2

    Coda::stampa(c1); // stampa [3, 4, ]
    Coda::stampa(c2); // stampa [5, ]

    return 0;
}