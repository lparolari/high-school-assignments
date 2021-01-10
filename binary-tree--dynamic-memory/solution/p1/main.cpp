#include <iostream>
#include <string>

#include "albero.hpp"
#include "nodo.hpp"

int main()
{
    // Vogliamo costruire l'albero
    //           3
    //       1       2

    // Costruisco i nodi n1 ed n2
    Nodo::Nodo *n1 = Nodo::costruisci(1);
    Nodo::Nodo *n2 = Nodo::costruisci(2);

    // Trasformo n1 ed n2 in due alberi a1 e a2
    Albero::Albero *a1 = Albero::costruisci(n1);
    Albero::Albero *a2 = Albero::costruisci(n2);

    // Costruisco l'albero a3 avente come radice il nodo n3
    Nodo::Nodo *n3 = Nodo::costruisci(3);
    Albero::Albero *a3 = Albero::costruisci(n3);

    // Creo un nuovo albero avente come radice la radice dell'albero a3 e
    // come figlio sinistro la radice dell'albero a1, come figlio destro la
    // radice dell'albero a2
    Albero::Albero *finale = Albero::unisci(a3, a1, a2);

    // // stampa il valore del nodo radice di a3
    // std::cout << std::to_string(Nodo::valore(Albero::radice(finale))) << std::endl;

    // // stampa il valore del nodo radice dell'albero figlio sinistro di a3
    // std::cout << std::to_string(Nodo::valore(Albero::radice(Albero::sx(finale)))) << std::endl;

    // // stampa il valore del nodo radice dell'albero figlio destro di a3
    // std::cout << std::to_string(Nodo::valore(Albero::radice(Albero::dx(finale)))) << std::endl;

    Albero::visita_in_profondita_postorder(finale);

    return 0;
}

/*

OUTPUT

3
1
2

*/
