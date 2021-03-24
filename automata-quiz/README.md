# Automi a stati finiti deterministici

## Esercizi

### Ex. 1

Dimostrare la non calcolabilità di tutti i problemi. Descrivere
brevemente il principio della dimostrazione: perché funziona? Perché
ci dice che non possiamo calcolare tutto?

### Ex. 2

Scrivere la definizione formale di automa a stati finiti
deterministico.

### Ex. 3

Tradurre la seguente tabella di transizione in un automa. Lo stato
iniziale è $q_0$. Gli stati acettati sono $F = \{ q_1 \}$. Definire
formalmente l'automa ricavato. Quale linguaggio riconosce questo
automa?

|     | 0   | 1   |
| --- | --- | --- |
| q0  | q0  | q1  |
| q1  | q0  | q2  |
| q2  | q1  | q0  |

### Ex. 4

Costruire un automa sull'alfabeto $\Sigma = \{ a, b \}$ in grado di
accettare tutte le stringhe che contengono `aba`.

### Ex. 5

Dimostrare la seguente proprietà sfruttando, qualora necessario, lemmi
visti a lezione. Si ottengono punti extra se vengono dimostrati anche
i lemmi utilizzati.

Siano $u$ e $v$ due stringhe, e $q$ uno stato. Se
$\hat\delta(q, u) = q_1$ e $\hat\delta(q, uv) = q_2$ allora
$\hat\delta(q_1, v) = q2$.
