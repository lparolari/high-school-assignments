# Array Analysis

## Task

Scrivere un programma che realizza alcune operazioni su array. Il
programma, in particolare, deve implementare le seguenti funzionalità.

1. **Stampa**. Dato un array _A_ e la sua lunghezza _n_, la funzione
   stampa a video l'array con valori tutti su una linea separati da
   virgole. Vengono aggiunte le partentesi quadre per rendere chiaro
   il fatto che si sta parlando di array.

   _Esempio_. Dato `A = { 7, -2, 0, 1, 3, -8 }` allora a video verrà
   stampato `[ 7, -2, 0, 1, 3, -8, ]`.

2. **Elementi distinti**. Dato un array _A_ e la sua lunghezza _n_, la
   funzione deve dare in output un array _B_ con tutti e soli gli
   elementi distinti trovati in _A_ e restituire la lunghezza _m_
   dell'array _B_.

   _Esempio_. Dato `A = { 1, 2, 3, 1, 2, 3, 4 }` allora
   `distinti(A) = { 1, 2, 3, 4 }`.

3. **Massimo**. Dato un array _A_ e la sua lunghezza _n_, la funzione
   deve restituire il valore massimo trovato all'interno dell'array
   _A_. Attenzione al caso array vuoto.

   _Esempio_. Dato `A = { 1, -13, 0, 4, 3, 7 }` allora `max(A) = 7`.

4. **Minimo**. Dato un array _A_ e la sua lunghezza _n_, la funzione
   deve restituire il valore minimo trovato all'interno dell'array
   _A_. Attenzione al caso array vuoto.

   _Esempio_. Dato `A = { 7, -2, 0, 1, 3, -8 }` allora `min(A) = -8`.

5. **Normalizzazione**. Dato un array _A_ e la sua lunghezza _n_, la
   funzione deve dare in output un array _B_ con i valori di _A_
   scalati a valori tra _0_ e _1_ e restituire la lunghezza dell'array
   _B_. La normalizzazione può essere ottenuta, nel caso di sequenze
   di soli valori positivi (_>= 0_), dividendo ogni elemento per il
   max dell'array.

   Estendere il problema nel caso di array con possibili valori
   negativi. (Volutamente non sono forniti dettagli.)

   _Esempio_

   Dato `A = { 5, 13, 0, 3, 3, 7 }` allora
   `norm(B) = { 0.38, 1, 0, 0.23, 0.23, 0.53 }`.

   Dato `B = { -4, 2, -7, 15, 12, 3 }` allora
   `norm(B) = { 0.14, 0.40, 0, 1, 0.86, 0.45 }`.

6. **Numero di volte**. Dato un array _A_ e la sua lunghezza _n_, la
   funzione deve dare in output un array _B_ contentente, per ogni
   valore distinto in _A_, il numero di volte che esso è stato trovato
   in _A_ e restituire la lunghezza _m_ di _B_.

   _Esempio_

   Dato `A = { 7, 4, 7, 1, -5, 7, 1 }` allora
   `distinti(A) = { 7, 4, 1, -5 }` e `occorrenze(A) = { 3, 1, 2, 1 }`.

_Nota_. Gli esempi seguono una notazione matematica.

_Nota_. Se più comodo, si implementare le funzionalità in main
diversi.

_Attenzione_. Il `main` deve contenere obbligatoriamente dei **test**
per le funzioni implementate, ovvero chiamate alle funzioni e stampe
dei valori restituiti. Non è necessario invece implementare nessuna
interazione con l'utente.

_Attenzione_. Tutte le funzionalità riportate devono essere
obbligatoriamente implementate come funzioni.

## Cosa consegnare

Consegnare _solamente_ i file sorgenti in un formato testuale. _No_
screenshot, _no_ file di word.
