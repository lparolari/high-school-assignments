# Macchina di Turing

Leggere attentamente le domande e fornire una risposta. Preferire
risposte _brevi_ e, dove possibile, descrizioni matematiche.

## Esercizi

### Ex. 1

Cos'è la macchina di Turing? Definirla formalmente.

### Ex. 2

Cosa afferma la tesi di Church-Turing?

### Ex. 3

Qual è il significato di una _funzione parziale_ e in che contesto
troviamo le funzioni parziali nella macchina di Turing?

E' possibile implementare una funzione parziale con macchina di
Turing? E con un linguaggio di programmazione tipo C++ o JavaScript?
Se sì, fornire un esempio sia per la MdT che per un linguaggio di
programmazione a piacere.

### Ex. 4

Dare la definizione formale di _descrizione instantanea_ per una
macchina di Turing.

Data la seguente macchina di turing, simulare un esercuzione e
riportare, ad ogni passo di computazione, la configurazione
instantanea della macchina.

```
q0 $ -> q1 0 R
q0 0 -> q2 0 L
q1 $ -> q0 0 L
q1 0 -> q1 0 R
q2 $ -> q1 0 L
q2 0 -> q4 0 R
```

Input:

```
... $ $ $ $ $ $ $ ...
          ^
          |  (q0)
```

Mostrare la configurazione di output ottenuta.

### Ex. 5

Scrivere la funzione di transizione per la macchina di turing che
determina quali tra due stringhe unarie è la più lunga. La macchina
progettata dovrà tenere conto anche del caso in cui le due stringhe di
input abbiano la stessa lunghezza.

Esempio 1:

```
INPUT:   ... $ $ $ 0 0 0 # 0 0 0 0 0 $ $ $ ...
                         ^
OUTPUT:  ... $ $ $ 0 0 0 # 0 0 0 0 0 $ $ $ ...
                                     ^
```

Esempio 2:

```
INPUT:   ... $ $ $ 0 0 0 # 0 0 0 $ $ $ ...
                         ^
OUTPUT:  ... $ $ $ 0 0 0 # 0 0 0 $ $ $ ...
                         ^
```

**Nota**: in questo caso è stato utilizzato `#` come simbolo
separatore per le due stringhe.

**Attenzione**: NON è richiesto che il nastro in output contenga
esattamente le due stringhe fornite come input. E' facile infatti
scrivere un programma (MdT) che dato un nastro "sporco" sostituisce
tutti i simboli diversi da `$` e `#` in `0`.
