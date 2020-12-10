#include <iostream>
#include "lista.hpp"

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;

    Lista::Lista l1 = Lista::costruisci_da_array(A, n);

    std::cout << "l1 = " << Lista::to_str(l1) << std::endl;
    std::cout << "l1[3] = " << Nodo::valore(Lista::primo(Lista::accedi(l1, 3))) << std::endl;
    std::cout << "l1[0] = " << Nodo::valore(Lista::primo(Lista::accedi(l1, 0))) << std::endl;
    std::cout << "l1[4] = " << Nodo::valore(Lista::primo(Lista::accedi(l1, 4))) << std::endl;
    std::cout << "dim = " << Lista::dimensione(l1) << std::endl;

    l1 = Lista::inserisci_fondo(l1, 6);
    std::cout << "l1 = " << Lista::to_str(l1) << std::endl;

    l1 = Lista::inserisci_inizio(l1, 7);
    std::cout << "l1 = " << Lista::to_str(l1) << std::endl;

    Lista::Lista l2 = Lista::cerca(l1, 3);
    std::cout << "l2 = " << Lista::to_str(l2) << std::endl;
    std::cout << "primo(l2) = " << Nodo::valore(Lista::primo(l2)) << std::endl;
    std::cout << "ultimo(l2) = " << Nodo::valore(Lista::ultimo(l2)) << std::endl;

    Lista::Lista l5 = Lista::costruisci_vuota();
    l5 = Lista::inserisci_fondo(l5, 10);
    std::cout << "l5 = " << Lista::to_str(l5) << std::endl;

    // Alcuni problemi di memoria condivisa ...

    Lista::Lista l3 = Lista::rimuovi_inizio(l2);
    std::cout << "l3 = " << Lista::to_str(l3) << std::endl;
    std::cout << "l2 = " << Lista::to_str(l2) << std::endl;

    Lista::Lista l4 = Lista::rimuovi_fondo(l2);
    std::cout << "l4 = " << Lista::to_str(l4) << std::endl;
    std::cout << "l2 = " << Lista::to_str(l2) << std::endl;

    return 0;
}

// Output
/*
    l1 = [ 1, 2, 3, 4, 5,  ]
    l1[3] = 4
    l1[0] = 1
    l1[4] = 5
    dim = 5
    l1 = [ 1, 2, 3, 4, 5, 6,  ]
    l1 = [ 7, 1, 2, 3, 4, 5, 6,  ]
    l2 = [ 3, 4, 5, 6,  ]
    primo(l2) = 3
    ultimo(l2) = 6
    l5 = [ 10, ]
    l3 = [ 4, 5, 6,  ]
    l2 = [ 3, 4, 5, 6,  ]
    l4 = [ 3, 4, 5,  ]
    l2 = [ 3, 4, 5,  ]
*/