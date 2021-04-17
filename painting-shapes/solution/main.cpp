#include <iostream>
#include <string>

class Forma
{
public:
    virtual double superficie() = 0;
};

class Rettangolo : public Forma
{
private:
    double base;
    double altezza;

public:
    Rettangolo(double b, double a)
    {
        base = b;
        altezza = a;
    }

    virtual double superficie()
    {
        return this->base * this->altezza;
    }
};

class Pittura
{
private:
    double copertura; // quanti metri quadrati sono pitturati con un litro
public:
    Pittura(double copertura)
    {
        this->copertura = copertura;
    }
    double quantita(Forma *forma)
    {
        return forma->superficie() / copertura;
    }
};

int main()
{
    Pittura acrilica(4);
    Pittura olio(2);

    Forma *rettangolo = new Rettangolo(2, 2);

    std::cout << "Rettangolo acrilico  = " << acrilica.quantita(rettangolo) << std::endl; // DA COMPLETARE
}
