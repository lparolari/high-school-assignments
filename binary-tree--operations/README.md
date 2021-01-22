# Operazioni su albero binario

## Consegna

Implementare le seguenti operazioni sull'albero binario. Il codice
sorgente che implementa le funzionalità base dell'albero binario è
fornito in allegato a questo documento.

1. **Verifica dell'esistenza di un elemento**. Dati _A_ e _v_
   rispettivamente un albero binario di ricerca (ordinato) e un valore
   intero, la funzione deve restituire vero se un elemento _v_ viene
   nell'albero _A_, falso altrimenti.

2. **Stampare l'albero tramite una vistia in ampiezza**. Dato _A_
   un'albero, implementare una funzione che effettua la visita
   dell'albero per livelli, in ampiezza appunto. La funzione può
   limitarsi inizalmente a stampare a video ogni nodo non appena viene
   incontrato durante la visita a livelli dell'albero.

3. **(opzionale) To array** . Dati _A_ unl'albero, implementare una
   funzione che "trasforma" l'albero _A_ (gerarchico) in un array
   (piatto). La trasformazione dell'albero in array può essere
   effettuata tramite uno qualunque dei metodi di vistia degli alberi,
   basta che venga specificato. La funzione quindi

   _Suggerimento_. L'array viene costruito in modo gerarchico man mano
   che si visita l'albero, inizialmente l'array sarà vuoto e poi man
   mano verrà popolato dalle radici dei sottoalberi visitati.

   _Suggerimento_. Utilizzare i vector anzichè gli array tipo C.

   _Suggerimento_. Vedere la documentazione delle funzioni `push_back`
   e `insert` dei vector, potrebbero risultare comode.

## Note

### Per gli utilizzatori di Dev-C++

Se riscontrate errori di compilazione probabilmente è perché Dev-C++
sta tentando di compilare il vostro codice con una versione obsoleta
del linguaggio C++.

_Soluzione_. ([Fonte](https://stackoverflow.com/a/16951613/5166003)).
Andare in _Tools -> Compiler options -> Compiler_ tramite il menu di
Dev-C++. Dovreste trovare una voce _Add the following commands when
calling the compiler_, lì potete aggiungere la seguente opzione di
compilazione

```
-std=c++11
```

e salvare.
