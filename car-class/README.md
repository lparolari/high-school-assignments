# Car Class

## Consegna

Realizzare una classe `Automobile`. Un automobile può essere creata
passando obbligatoriamente il numero di chilometri percorsi con un
litro $kl$ e opzionalmente il numero di litri di carburante nel
serbatoio $s$ (default $s = 30$ l).

Un'automobile appena creata ha il serbatoio pieno, è spenta e ha
percorso 0 km.

La classe inoltre realizza le seguenti funzionalità.

- Accendere il motore. Questa funzionalità permette di accendere il
  motore, il motore non viene riacceso se lo era già.

- Spegnere il motore. Questa funzionalità permette di spegnere il
  motore, il motore non viene spento nuovamente se lo era già.

- Vedere carburante. Permette di visualizzare il carburante rimanente
  nel serbatoio.

- Aggiungere carburante. Riempie il serbatoio fino ad un massimo di 20
  litri di carburante.

- Viaggiare per _n_ chilometri. L'automobile viaggia per _n_
  chilometri e consuma $n * kl$ dove $kl$ è il numero di chilometri
  effettuati con un litro, specificato durante la creazione della
  macchina.

- Vedere il numero di chilometri percorsi $kp$.

## Esempio di utilizzo

```cpp
Automobile alfa(5);     // kl = 5, s = 30
Automobile bmw(20, 20); // kl = 20, s = 20

alfa.accendi();
alfa.viaggia(20);
std::cout << alfa.carburante() << std::endl; // 26
alfa.riempi();
alfa.viaggia(30);
std::cout << alfa.carburante() << std::endl; // 24
std::cout << alfa.km_percorsi() << std::endl; // 50

bmw.viaggia(80);
std::cout << bmw.carburante() << std::endl; // 20
std::cout << bmw.km_percorsi() << std::endl; // 0
bmw.accendi();
bmw.viaggia(80);
bmw.accendi();
bmw.viaggia(80);
std::cout << bmw.carburante() << std::endl; // 12
std::cout << bmw.km_percorsi() << std::endl; // 160
bmw.spegni();
bmw.viaggia(80);
std::cout << bmw.carburante() << std::endl; // 12
std::cout << bmw.km_percorsi() << std::endl; // 160
```

## Estension1

1. Ottenere i dettagli dell'auto. Consente di ottenere una stringa
   specifica quanti chilometri sono stati percorsi dall'auto e
   fornisce una stima dei chilometri ancora percorribili in base al
   carburante disponibile.

```cpp
std::cout << bmw.dettagli() << std::endl;
    // Sono stati percorsi 160 km e se ne possono percorrere ancora 240.
```

2. Overloading dell'operatore `<<`. Consente di stampare a video i
   dettagli della macchina semplicemente mandando l'oggetto su un
   output stream.

```cpp
std::cout << bmw << std::endl;
    // Sono stati percorsi 160 km e se ne possono percorrere ancora 240.
```
