#include <iostream>
#include <vector>

using namespace std;

class Dipendente
{
private:
    std::string nome;
    std::string cognome;

public:
    Dipendente(std::string nome, std::string cognome)
    {
        this->nome = nome;
        this->cognome = cognome;
    }

    std::string presentazione()
    {
        return nome + " " + cognome;
    }

    virtual double paga() = 0;
};

class Impiegato : public Dipendente
{
private:
    double tariffa;

public:
    Impiegato(std::string nome, std::string cognome, double tariffa) : Dipendente(nome, cognome), tariffa(tariffa) {}

    virtual double paga()
    {
        return tariffa;
    }
};

class Orario : public Dipendente
{
private:
    double tariffa_oraria;
    int n_ore;

public:
    Orario(std::string nome, std::string cognome, double tariffa_oraria) : Dipendente(nome, cognome), tariffa_oraria(tariffa_oraria), n_ore(0) {}

    void aggiungi_ore(int ore)
    {
        n_ore += ore;
    }

    virtual double paga()
    {
        return n_ore * tariffa_oraria;
    }
};

class Volontario : public Dipendente
{
public:
    Volontario(std::string nome, std::string cognome) : Dipendente(nome, cognome) {}

    virtual double paga()
    {
        return 0.0;
    }
};

std::vector<Dipendente *> crea_dipendenti()
{
    Impiegato *impiegato = new Impiegato("a", "b", 1200.15);
    Orario *orario = new Orario("c", "d", 15.5);
    Volontario *volontario = new Volontario("e", "f");

    orario->aggiungi_ore(29);

    std::vector<Dipendente *> V;

    V.push_back(impiegato);
    V.push_back(orario);
    V.push_back(volontario);

    return V;
}

double calcola_totale(std::vector<Dipendente *> dipendenti)
{
    double paga = 0.;

    for (auto d : dipendenti)
    {
        paga += d->paga();
    }

    return paga;
}

int main()
{
    std::vector<Dipendente *> dipendenti = crea_dipendenti();

    std::cout << "Paga totale = " << calcola_totale(dipendenti) << std::endl;

    return 0;
}
