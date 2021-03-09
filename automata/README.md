# Deterministic Finite Automata

## Esercizi

### Ex. 1

Tradurre la tabella di transizione riportata di seguito in un automa
$M = \langle Q, \Sigma, \delta, q_0, F \rangle$ definendone
formalmente le sue parti e disegnando il grafo che lo rappresenta.

|       | 0     | 1     |
| ----- | ----- | ----- |
| $q_0$ | $q_2$ | $q_0$ |
| $q_1$ | $q_2$ | $q_0$ |
| $q_2$ | $q_1$ | $q_2$ |

### Ex. 2

Costruire un automa con $\Sigma = \{ 0, 1 \}$ che accetta stringhe su
sigma se, interpretate come numero binario, sono divisibili per 2.

_Suggerimento_: definire prima cosa significa che una stringa binaria
è divisibile per 2 e solo poi costruire l'automa.

### Ex. 3

Dimostrare la seguente proprietà. Siano $vx$ e $wx$ due stringe e
$M = \langle Q, \Sigma, \delta, q_0, F \rangle$ un DFA. Allora
$\hat\delta(q_0, v) = \hat\delta(q_0, w)$ implica
$\hat\delta(q_0, vx) = \hat\delta(q_0, wx)$.

_Suggerimento_: $vx$ e $wx$ sono due stringhe dove l'ultimo carattere
è proprio lo stesso. \
_Suggerimento_: un'implicazione può essere dimostrata assumendo che l'antecedente
(la parte prima della freccia) è vera e quindi, sfruttando questo fatto,
far vedere che anche la conseguente (la parte dopo la freccia) è vera.
Notare che in questo caso la "freccia" dell'implicazione ($\Rightarrow$)
è sostituta dalla parola "implica".
