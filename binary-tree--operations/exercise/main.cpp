#include <iostream>
#include <string>

#include "albero.hpp"

int main()
{
    std::vector<int> dati = {9, 6, 2, 7, 8, 3, 11, 5, 4, 0, 1};
    Albero::Albero *b = Albero::da_array(dati);

    Albero::stampa(b);

    int min_b = Albero::min(b);

    std::cout << "min = " << min_b << std::endl;

    return 0;
}