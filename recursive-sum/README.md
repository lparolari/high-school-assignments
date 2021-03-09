# Somma Ricorsiva

Si scriva un programma che calcola la seguete funzione

$$f(a, n) = \sum_{i = 1}^{n} (a - \frac{i}{a}).$$

Detto in altre parole, dati $a$ ed $n$, $f$ calcola la somma di
$a - \frac{i}{a}$ con $i$ che va da $1$ ad $n$.

Il programma deve obbligatoriamente avere due funzioni `f_iter` e
`f_rec` che implementano rispettivamente la versione iterativa e
quella ricorsiva del calcolo di $f$.

Testare poi nel mail i risultati delle due funzioni, che, ovviamente,
devono essere uguali.
