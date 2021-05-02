# Coda del Supermercato

Si supponga di dover realizzare un programma che gestisce la coda alle
casse di un supermercato di modo da poter poi redirigere i clienti
alle case più vuote.

Si ricorda che il contenitore "coda" consente di gestire gli elementi
che memorizza mediante operazioni ben definite proprio come una coda
al supermercato: il primo che arriva è il primo ad essere servito ed è
quindi il primo a essere rimosso dalla coda. Gli altri, arrivati
successivamente, si accodano e vengono estratti in ordine di arrivo.
Analogamente, nel mondo informatico possiamo vedere la coda come un
buffer FIFO (Fist In First Out).

La richiesta è divisa in due parti. Nella prima viene richiesto di
implementare la mera gestione della coda delle casse, ovvero prevedere
le funzioni per creare code, inserire/rimuovere elementi e così via.
Nella seconda parte invece è richiesto di gestire effettivamente la
redirezione dei clienti alle casse più scariche.

Vi è inoltre una terza parte (opzionale) che chiede di verificare una
proprietà sul criterio di gestione dei clienti adottato.

## Parte 1

Il programma deve implementare le seguenti funzionalità che realizzano
la coda basandosi _esclusivamente_ sui vector.

- Funzione `std::vector<int> costruisci_vuota()`. Restituisce una coda
  vuota.

- Funzione `void stampa(std::vector<int> C)`. Stampa la coda mostrando
  gli elementi tutti sulla stessa riga separati da spazio (o simboli
  adeguati).

- Funzione `std::vector inserisci(std::vector<int> C, int x)`. Riceve
  in input una coda `C` e un valore `x` e _restituisce_ la coda `C`
  aggiornata di modo che `x` sia stato messo in coda come ultimo
  elemento.

- Funzione `std::vector togli(std::vector<int> C)`. Riceve in input
  una coda `C` e _restituisce_ la coda `C` aggiornata di modo che il
  primo valore sia stato rimosso dalla coda.

- Funzione `bool vuota(std::vector<int> C)`. Riceve in input una coda
  `C` e restituisce `true` se la coda è vuota, `false` altrimenti.

- Funzione `int primo(std::vector<int> C)`. Riceve in input una coda
  `C` e restituisce il primo valore in coda.

- Funzione `int dimensione(std::vector<int> C)`. Riceve in input una
  coda `C` e restituisce il numero di elementi al suo interno.

**Nota**. L'obiettivo di queste funzioni è _mascherare_ il vector di
modo che l'utente possa gestire la coda veramente come una coda e non
possa quindi andare a modificare, inserire o rimuovere elementi in
modi non previsti.

### Esempio

Di seguito è fornito un main di esempio da poter utilizzare come test.

```cpp
#include <iostream>
#include <vector>

typedef std::vector<int> Coda;

int main() {
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
    if (!vuota(c2)){
        std::cout << primo(c2) << std::endl;
    }
    else {
        std::cout << "La lista e’ vuota!" << std::endl;
    }

    c1 = inserisci(c1, 4); // arriva il cliente 4 e va alla cassa 1
    c2 = inserisci(c2, 5); // arriva il cliente 5 e va alla cassa 2

    stampa(c1); // stampa [3, 4, ]
    stampa(c2); // stampa [5, ]
}
```

## Parte 2

Il programma deve implementare la gestione dei clienti alle code del
supermercato facendo in modo che le casse lavorino nel modo più
bilanciato possibile.

Il bilanciamento del carico di lavoro si basa su un'unica regola:

> ogni nuovo cliente è mandato alla cassa più scarica in quel momento.

Ad esempio, date `C1 = { 1, 2, 3 }` e `C2 = { 4 }` due casse con
rispettivamente 3 clienti e un cliente in fila, se arrivano 2 clienti,
ad esempio `5` e `6`, essi sono mandati alla cassa `C2`.

Il programma deve quindi prevedere le seguenti funzionalità.

- Funzione `servi` che dato in input un vector di code (casse) e
  l'indice di una coda, serve un cliente dell coda con indice dato.

- Funzione `gestisci` che prende in input un vector di code (casse) e
  un cliente e, in autonomia, decide dove inviare il cliente facendo
  in modo di bilanciare il carico di lavoro tra le casse.

- Funzione `visualizza` che prende in input un vector di code e le
  stampa a video mostrando, possibilemente, quanti clienti ancora sono
  in coda.

### Esempio

Di seguito è fornito un main di esempio da poter utilizzare come test.

```cpp
#include <iostream>
#include <vector>

typedef std::vector<int> Coda;

int main() {
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

    std::vector<Coda> casse = { c1, c2, c3 };

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
    casse = servi(casse, 0);  // servi un cliente alla cassa con indice 0
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
```

## Parte 3 (opzionale, con bonus)

E' facile verificare che partendo da una qualsiasi situazione
iniziale, ovvero clienti sparsi alle casse in qualunque modo, dopo un
(sufficiente) numero di passi, se nessun cliente viene servito essi
saranno distribuiti alle casse in egual numero a meno di 1 cliente di
diffirenza.

Ad esempio, data la situazione iniziale con 3 casse 5 cinque clienti
sparsi a caso su di esse

```
c1: X X X X
c2: X
c3:
```

dopo 5 passi si raggiunge la situazione seguente, tramite la quale è
facile vedere che le casse hanno tutte 4 oppure 3 clienti (scarto di 1
cliente)

```
c1: X X X X
c2: X X X
c3: X X X
```

La proprietà deducibile da questo esempio è che

$$floor \left( \frac{n}{c} \right) \leq dim(i) \leq ceil \left( \frac{n}{c} \right)$$

dove

- $dim(i)$ è la dimensione (numero di clienti) della cassa $i$,
- $n$ è il numero di clienti,
- $c$ è il numero di casse,
- $floor \left( \frac{n}{c} \right)$ è la parte intera inferiore della
  divisione tra $n$ e $c$,
- $ceil \left( \frac{n}{c} \right)$ è la parte intera superiore della
  divisione tra $n$ e $c$.

Dall'esempio sopra otteniamo che per ogni $i \in \{ 1, 2, 3 \}$
(ovvero per ogni cassa da 1 a 3)

$$floor \left( \frac{10}{3} \right) = 3 \leq dim(i) \leq 4 = ceil \left( \frac{10}{3} \right)$$

Scrivere un programma che verifica empiricamente (ovvero tramite
esperimenti) quanto indicato sopra.
