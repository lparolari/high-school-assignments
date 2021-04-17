#include <iostream>
#include <string>

class Forma { };  // DA COMPLETARE

class Sfera { };      // DA COMPLETARE 
class Rettangolo { }; // DA COMPLETARE
class Cilindro { };   // DA COMPLETARE

class Pittura
{
private:
    double copertura; // quanti metri quadrati sono pitturati con un litro
public:
    Pittura(double copertura)
    {
        this->copertura = copertura;
    }
    
    double quantita(Forma *forma);  // DA COMPLETARE
};

int main()
{
    Pittura acrilica(5);
    Pittura olio(2);

    Forma *sfera;       // DA COMPLETARE: istanziare la sfera
    Forma *rettangolo;  // DA COMPLETARE: istanziare il rettangolo
    Forma *cilindro;    // DA COMPLETARE: istanziare il cilindro

    std::cout << "ACRILICO" << std::endl;
    std::cout << "Forma      \t Quantità" << std::endl;
    std::cout << "-----      \t --------" << std::endl;
    std::cout << "Sfera      \t" << "TODO" << std::endl;  // DA COMPLETARE: sostituire "TODO" con il calcolo vero
    std::cout << "Rettangolo \t" << "TODO" << std::endl;  // DA COMPLETARE
    std::cout << "Cilindro   \t" << "TODO" << std::endl;  // DA COMPLETARE
    std::cout << "-----      \t --------" << std::endl;
    std::cout << "Totale     \t TODO" << std::endl;       // DA COMPLETARE
    
    std::cout << std::endl << "OLIO" << std::endl;
    std::cout << "Forma      \t Quantità" << std::endl;
    std::cout << "-----      \t --------" << std::endl;
    std::cout << "Sfera      \t" << "TODO" << std::endl;  // DA COMPLETARE
    std::cout << "Rettangolo \t" << "TODO" << std::endl;  // DA COMPLETARE
    std::cout << "Cilindro   \t" << "TODO" << std::endl;  // DA COMPLETARE
    std::cout << "-----      \t --------" << std::endl;
    std::cout << "Totale     \t TODO" << std::endl;       // DA COMPLETARE
}

