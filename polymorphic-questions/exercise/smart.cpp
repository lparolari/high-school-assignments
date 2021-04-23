#include <iostream>  // cout, endl
#include "smart.hpp" // SmartPointer

int main()
{
    int *x = new int(5); // x è la risorsa da gestire

    SmartPointer<int> pt1(x);

    std::cout << *(pt1.get()) << std::endl; // 5

    std::cout << pt1.num_ref() << std::endl; // 1

    SmartPointer<int> pt2(pt1);

    std::cout << pt1.num_ref() << std::endl; // 2
    std::cout << pt2.num_ref() << std::endl; // 2

    // Creo un blocco
    {
        SmartPointer<int> pt3 = pt2;

        std::cout << pt1.num_ref() << std::endl; // 3
        std::cout << pt2.num_ref() << std::endl; // 3
        std::cout << pt3.num_ref() << std::endl; // 3

        // Qui viene deallocato pt3
    }

    std::cout << pt1.num_ref() << std::endl; // 2
    std::cout << pt2.num_ref() << std::endl; // 2

    // Qui vengono deallocati sia pt1 che pt2,
    // x viene quindi automaticamente deallocato
    // dall'ultimo smart pointer che muore (pt2)
}
