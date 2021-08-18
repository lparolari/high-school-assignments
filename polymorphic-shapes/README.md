# Figure Geometriche

Scrivere un programma per il calcolo dell'area di figure geometriche diverse 
tra loro (rettangolo, cerchio, rombo, triangolo, ...).

Implementare una classe astratta `FiguraGeometrica` (superclasse), la quale 
ha un unico metodo astratto (senza implmentazione) di nome `area` che 
restituisce `double`.

Implementare anche due classi derivate `Rettangolo` e `Cerchio` (devono estendere
obbligatoriamente la superclasse `FiguraGeometrica`). 

* Per quanto riguarda la classe `Rettangolo` essa deve avere un costruttore che prende in input base e altezza (due double) e li salva come attributi privati. Il metodo `area` per la classe quadrato deve essere implementato come $base * altezza$. 

* Per quanto riguarda la classe `Cerchio` essa deve avere un costruttore che prende in input il raggio (double) e lo salva come attributo privato. Il metodo `area` per la classe cerchio deve essere implementato come $raggio^2 * pi$ (nota: $raggio^2 = raggio*raggio$, $pi = 3.1415$).

Testare nel main quanto implementato. Creare le due figure geometriche quadrato e cerchio con valori arbitrari (salvandole in variabili con il tipo `FiguraGeometrica`), invocare su diesse il metodo area e stampare a video il risultato.
