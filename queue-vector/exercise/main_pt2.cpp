#include <iostream>
#include <vector>

typedef std::vector<int> Coda;

// RIPORTARE LE FUNZIONI SULLA CODA SCRITTE NELLA PARTE 1

// SCRIVERE QUI LE FUNZIONI PER LA PARTE 2

int main()
{
    Coda c1 = costruisci_vuota();
    Coda c2 = costruisci_vuota();
    Coda c3 = costruisci_vuota();

    // Simuliamo una congestione alla cassa 1
    // In cassa 2 rimane un solo cliente
    // La cassa 3 invece è vuota

    c1 = inserisci(c1, 1);
    c1 = inserisci(c1, 2);
    c1 = inserisci(c1, 3);
    c1 = inserisci(c1, 4);

    c2 = inserisci(c2, 5);

    // Mettiamo le casse in un vector per poterle
    // passare alla funzione che le gestisce

    std::vector<Coda> casse = {c1, c2, c3};

    // Mostriamo a video lo stato delle nostre casse

    visualizza(casse);
    // cassa 1, ancora 4 clienti in attesa: [ 1, 2, 3, 4, ]
    // cassa 2, ancora 1 clienti in attesa: [ 5, ]
    // cassa 3, ancora 0 clienti in attesa: [ ]

    // A questo punto i nuovi clienti che arrivano,
    // dovrebbero essere smistati principalmente sulle casse
    // c2 e c3

    casse = gestisci(casse, 6);

    // Mostriamo a video lo stato delle casse dopo aver
    // ricevuto il cliente 6

    visualizza(casse);
    // cassa 1, ancora 4 clienti in attesa: [ 1, 2, 3, 4, ]
    // cassa 2, ancora 1 clienti in attesa: [ 5, ]
    // cassa 3, ancora 1 clienti in attesa: [ 6, ]

    casse = gestisci(casse, 7);
    casse = gestisci(casse, 8);
    casse = servi(casse, 0); // servi un cliente alla cassa con indice 0
    casse = gestisci(casse, 9);

    visualizza(casse);
    // cassa 1, ancora 3 clienti in attesa: [ 2, 3, 4, ]
    // cassa 2, ancora 3 cliente in attesa: [ 5, 7, 9, ]
    // cassa 3, ancora 2 clienti in attesa: [ 6, 8, ]

    casse = servi(casse, 0);
    casse = servi(casse, 0);
    casse = servi(casse, 2);
    casse = gestisci(casse, 10);

    visualizza(casse);
    // cassa 1, ancora 2 clienti in attesa: [ 4, 10, ]
    // cassa 2, ancora 3 cliente in attesa: [ 5, 7, 9, ]
    // cassa 3, ancora 1 clienti in attesa: [ 6, ]
}
