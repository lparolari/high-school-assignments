#include "Albero.hpp"
#include "Nodo.hpp"

#include <iostream>

int main()
{
    // Costruiamo l'albero
    //         0
    //     1       2
    //   3   4

    Albero::Albero *a11 = Albero::costruisci(Nodo::costruisci(3));
    Albero::Albero *a12 = Albero::costruisci(Nodo::costruisci(4));

    Albero::Albero *a1 = Albero::unisci(Albero::costruisci(Nodo::costruisci(1)), a11, a12);

    Albero::Albero *a2 = Albero::costruisci(Nodo::costruisci(2));

    Albero::Albero *a = Albero::unisci(Albero::costruisci(Nodo::costruisci(0)), a1, a2);

    std::cout << Nodo::valore(Albero::radice(a)) << std::endl;             // 0
    std::cout << Nodo::valore(Albero::radice(Albero::sx(a))) << std::endl; // 1
    std::cout << Nodo::valore(Albero::radice(Albero::dx(a))) << std::endl; // 2

    std::cout << Albero::to_str(a) << std::endl; // 0 1 3 4 2
}
