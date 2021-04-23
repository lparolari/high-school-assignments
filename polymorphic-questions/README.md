# Polymorphic Questions

Si supponga di dover implementare un sistema simile a Google Moduli o
Forms di Microsoft per raccogliere le risposte delle verifiche svolte
online.

Nella prima parte del task, viene richiesto di implementare la
gestione delle domande tramite il polimorfismo dinamico. Nella seconda
parte invece si richiede di implementare una gestione corretta della
memoria dinamica utilizzando gli smart pointers.

# Parte 1

Implementare il sistema di Q&A secondo le specifiche che seguono.
Questa parte del sistema deve essere implementata tramite polimorfismo
dinamico (ove possibile).

Maggiori dettagli sono deliberatamente non forniti e possono essere
scelti da chi implementa il sistema.

## Specifiche

### Moduli

Il sistema permette di creare moduli, ovvero una collezione di domande
possibilmente di tipo diverso, e di compilarli. La compilazione (sia
input che output) viene effettuata tramite linea di comando.

Il modulo consente di visualizzare quante domande corrette sono state
date e il numero totale di domande nel modulo.

### Domande

Una domanda è l'insieme delle parole con cui si esprime la richiesta
di qualcosa
([Treccani](https://www.treccani.it/vocabolario/domanda/)). In questo
contesto una domanda viene vista come un concetto astratto con le
seguenti proprietà.

- Deve essere formata da del testo che rappresenta la domanda stessa;
- Può avere un feedback che viene mostrato nel caso la risposta data
  sia inesatta;
- Deve essere possibile mostrarla a video. La formattazione della
  domanda dipende dal suo tipo (vedere la sezione Esempi per maggiori
  informazioni);
- Deve poter essere data una risposta alla domanda;
- Deve avere un modo per verificare che la risposta data sia corretta
  o meno;

### Risposte

Il sistema deve essere ingrado di raccogliere diversi tipi di risposte
alle domande previste da un modulo. I tipi di risposte supportati sono
i seguenti.

- Risposta aperta. L'utente risponde con del testo libero.
- Scelta singola. L'utente risponde con una delle _N_ opzioni fornite.
- Scelta multipla. L'utente risponde con zero, una o più opzioni tra
  le _N_ fornite. Se l'utente risponde con più opzioni di quelle
  corrette la risposta viene considerata errata.
- Data. L'utente risponde con una data in formato `dd/mm/YYYY` (es:
  23/04/2021).
- Scala lineare. L'utente risponde con un valore da una scala di
  valori fornita.

## Esempi

```
Qual era il colore del cavallo bianco di napoleone?
0) Bianco
1) Verde
2) Rosa
3) Arcobaleno
Risposta: 3
Risposta errata (Bianco, Watson!)

Qual è la data della scoperta dell'america?
Risposta (dd/mm/YYYY): 12/10/1493
Risposta errata (12/10/1492)

Qual è il nome dell'oceano tra Europa e America?
Risposta: Atlantico

Quale delle seguenti affermazione è corretta?
1) Le rose sono rosse
2) Le viole sono blu
3) 42
Risposte (-1 per terminare): 1
Risposte (-1 per terminare): 3
Risposte (-1 per terminare): -1
Risposta corretta

Quanto sono sensate queste domande?
Scegli un valore da 1 a 10
Risposta: 2
Risposta errata (Non lo sono affatto)

Risposto correttamente a 2 domande su 5
```

# Parte 2

Avendo avuto a che fare con la memoria dinamica nella parte 1 del
sistema, vi viene richiesto di gestire correttamente questa memoria.
Per farlo dovete utilizzare gli _smart pointers_.

Gli smart pointers (o puntatori intelligenti), sono degli strumenti
che permetto di gestire agevolmente la memoria dinamica allocata per
un oggetto e, in particolare, evitano allo sviluppatore di dover
gestire manualmente l'allocazione (new) e la dellocazione (delete)
degli oggetti.

Più concretamente, uno smart pointer memorizza un puntatore
all'oggetto che deve gestire e il numero di reference a quell'oggetto.
Lo smart pointer infatti quando viene costruito, copiato o assegnato
aggiorna un contatore interno che gli permette di sapere quanti smart
pointers stanno utilizzando la risorsa in gestione. L'ultimo smart
pointer rimasto, quando viene distrutto deve deallocare la memoria
dell'oggetto in gestione.

## Specifiche

Lo smart pointer deve esporre la seguente interfaccia.

- _Costruttore_. Costruzione di uno smart pointer con un puntatore a
  tipo generico T. Uno smart pointer appena creato imposta il numero
  di reference all'oggetto da proteggere a 1.

- _Costruttore di copia_. Copia di uno smart pointer. Viene assegnato
  internamente il puntatore da proteggere e viene incrementato di 1 il
  numero di reference che puntano alla risorsa.

- _Operatore di assegnamento_. Assegnamento di uno smart pointer.
  Viene assegnato internamente il puntatore da proteggere e viene
  incrementato di 1 il numero di reference che puntano alla risorsa.

- _Distruttore_. Distrugge lo smart pointer e, se il numero di refence
  rimasti verso la risorsa sono $\leq 1$ allora dealloca la risorsa.

- _Get_. Restituisce il puntatore alla risorsa da progeggere.

- _Reference numeber_. Restituisce il numero di reference che puntano
  alla risorsa.

```cpp
template <typename T>
class SmartPointer
{
private:
    // Puntatore alla risorsa da gestire
    T *_pt = nullptr;
    // Puntatore ad un int che rappresenta il numero di riferimenti
    // che puntano alla risorsa gestita. Questa variabile è gestita
    // tramite memoria dinamica perché si ha bisogno che sia condivisa
    // tra tutti gli smart pointer che usano la risorsa.
    int *_ref_number = nullptr;

public:
    // Crea un nuovo smart pointer memorizzando il puntatore ad una
    // risorsa e imposta ad 1 il numero di reference che puntano ad
    // essa.
    SmartPointer(T *pt);

    // Copia `other` nell'oggetto this. Provoca l'incremento del
    //  numero di reference che puntano alla risorsa.
    SmartPointer(const SmartPointer &other);

    // Assegna `other` all'oggetto this. Provoca l'incremento del
    // numero di reference che puntano alla risorsa.
    SmartPointer &operator=(const SmartPointer &other);

    // Distruttore. Dealloca le risorse se `num_ref()` è minore
    //  o uguale a 1.
    ~SmartPointer();

    // Restituisce il numero di reference che puntano alla risorsa.
    int num_ref();

    // Restiuisce il puntatore alla risorsa interna.
    T *get();
};
```

## Esempi

```cpp
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
```

# Parte 3 (opzionale)

Adattare il codice scritto nella parte 1 per includere l'utilizzo
degli smart pointers implementati nella parte 2.
