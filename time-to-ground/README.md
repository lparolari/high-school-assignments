# Esercizio

## Consegna

Scrivere un programma il cui compito è calcolare il tempo di caduta di
un oggetto data una certa accelerazione di gravità.

### Tempo di caduta

Il programma deve fornire una funzione che data _h_ un'altezza (m) e
_a_ un'accelerazione (m/s^2) calcola il tempo _t_ (s) impiegato da un
oggetto a cadere al livello del suolo.

Si ricorda che nel caso di caduta libera di un oggetto la formula per
calcolare il tempo _t_ di caduta è

> _t = sqrt(2h / g)_

con

- _sqrt_ = radice quadrata
- _h_ = altezza
- _g_ = accelerazione di gravità

Testare la funzione implementata.

### Pianeti diversi

Si progetti poi un'altra funzione che dato il numero di un pianeta _n_
e l'altezza _h_, applica il calcolo della caduta con le seguenti
regole:

| numero | pianeta | accelerazione di gravità (m/s^2) |
| ------ | ------- | -------------------------------- |
| 0      | terra   | _9.81_                           |
| 1      | luna    | _1.62_                           |
| 2      | marte   | _3.71_                           |

Testare la funzione implementata.

### Interfaccia

Realizzare un'interfaccia a riga di comando che chiede in input
all'utente un pianeta, un'altezza e calcola il tempo di caduta al
suolo di un corpo sul pianeta dato. Quest'interfaccia deve fare uso
delle funzioni progettate ed implementate precedentemente.

Attenzione! Quest'interfaccia non deve sostituire i test delle
funzioni. E' consigliato scrivere in un altro file il codice di questa
parte dell'esercizio.

_Esempio_.

```
pianeta? [0=terra/1=luna/2=marte]: *0*
altezza (m)?: *10*

tempo di caduta (s): 1.427843123
```

Attenzione: il testo marcato da asterisco (\*) indica l'input
dell'utente.
