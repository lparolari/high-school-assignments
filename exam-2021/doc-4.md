# Tutte le funzioni sono calcolabili?

Assumiamo che tutte le funzioni siano calcolabili.

Supponiamo di definire un formalismo che ci permetta di codificare
algoritmi nella loro forma più semplice: funzioni che trasformano un
input in un output (con input e output numeri naturali).

Supponiamo inoltre che gli algoritmi che vogliamo trattare rispettino
i requisiti fondamentali di un algoritmo (essere sequenze finite di
passi elementari, esiste agente che porta avanti la compiutazione in
modo meccanico, il calcolo non è probabilistico, ...).

Da queste assunzioni segue che possiamo _enumerare_ tutti i possibili
programmi che possiamo scrivere con il nostro formalismo, ovvero
esiste una corrispondenza biunivoca tra un numero naturale e un
programma.

Fissiamo un generico programma $P_n$.

Costruiamo ora il seguente problema

_input_: $k$ \
determina il programma $P_k$ \
calcola $P_k(k)$ \
_output_: $P_k(k) + 1$

Se possiamo codificare questo programma allora esso assumerà un
indice, supponiamo l'indice sia un generico numero _m_.

Chiamiamo $h = P_m$, ovvero $h$ è il programma con indice $m$.

Ma allora avremmo

$$h(m) = P_m(m) = P_m(m) + 1 =  h(m) + 1$$

che è un assurdo! Quindi, l'assunto è errato: non tutte le funzioni
sono calcolabili, alcune, come quella definita, non lo sono.
