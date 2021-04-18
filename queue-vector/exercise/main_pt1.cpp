#include <iostream>
#include <vector>

typedef std::vector<int> Coda;

// SCRIVERE QUI LE FUNZIONE PER GESTIRE LA CODA

int main()
{
    Coda c1 = costruisci_vuota(); // fila alla cassa 1
    Coda c2 = costruisci_vuota(); // fila alla cassa 2

    c1 = inserisci(c1, 1); // arriva il cliente 1 e va alla cassa 1
    c2 = inserisci(c2, 2); // arriva il cliente 2 e va alla cassa 2
    c1 = inserisci(c1, 3); // arriva il cliente 3 e va alla cassa 1

    std::cout << dimensione(c1) << std::endl; // restituisce 2
    std::cout << dimensione(c2) << std::endl; // restituisce 1

    std::cout << primo(c1) << std::endl; // restituisce 1 (il cliente 1)

    stampa(c1); // stampa [1, 3, ]
    stampa(c2); // stampa [2, ]

    c1 = togli(c1); // viene servito il cliente 1 della cassa 1
    c2 = togli(c2); // viene servito il cliente 2 della cassa 2

    stampa(c1); // stampa [3, ] che sono i clienti ancora in attesa allacassa 1
    stampa(c2); // stampa [] che sono i clienti ancora in attesa allacassa 2(nessuno !)

    // Visualizza il primo cliente della cassa c2 (se esiste!)
    if (!vuota(c2))
    {
        std::cout << primo(c2) << std::endl;
    }
    else
    {
        std::cout << "La lista e’ vuota!" << std::endl;
    }

    c1 = inserisci(c1, 4); // arriva il cliente 4 e va alla cassa 1
    c2 = inserisci(c2, 5); // arriva il cliente 5 e va alla cassa 2

    stampa(c1); // stampa [3, 4, ]
    stampa(c2); // stampa [5, ]
}
