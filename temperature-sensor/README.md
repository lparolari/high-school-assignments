# Sensore di Temperatura

Supponiamo di voler leggere i dati di un sensore di temperatura e di
volerli loggare da qualche parte su un file per analizzare l'andamento
delle temperature sull'arco di tempo di una settimana.

Il sensore della temperature è un sensore low-budget che ha una
frequenza di campionamento di 1 Hz, ovvero può essere letto solo 1
volta al secondo: se viene letto più spesso di 1 volta al secondo
questo restituisce lo stesso risultato della lettura "vera".

Esempio di lettura corretta (frequenza = 1 Hz):

```
*tempo*:           0     1     2     3     4     5  ...
*temperatura*:  20.1  20.2  20.1  20.2  20.3  20.2  ...
```

Esempio di lettura non corretta (frequenza = 2 Hz):

```
*tempo*:           0   0.5     1   1.5     2   2.5     3   3.5  ...
*temperatura*:  20.1  20.1  20.2  20.2  20.1  20.1  20.2  20.2  ...
```

Supponiamo di implementare un sensore fake che simula questa logica.

```typescript
class Termometro {
  private ultimaLettura: Date = null;
  private temperatura: number = 0;

  leggiTemperatura() {
    const adesso = new Date();

    // restituisco ultima temperatura se la lettura è stata
    // fatta prima di 1 secondo dall'ultima lettura "vera"
    if (
      this.ultimaLettura &&
      adesso.getTime() - this.ultimaLettura.getTime() < 1000
    ) {
      return this.temperatura;
    }

    // aggiorno la data dell'ultima lettura
    this.ultimaLettura = new Date();

    // rilevo nuova temperatura (presa a caso tra 20 e 21 gradi)
    this.temperatura = Math.random() + 20;

    return this.temperatura;
  }
}
```

Come si può notare, la funzione `leggiTemperatura` restituisce lo
stesso valore se letta più volte in un secondo, mentre restituisce
temperature nuove altrimenti.

Il problema ora è: come fare a loggare le temperature una volta al
secondo?

Il problema principale con la programmazione "tradizionale" è che non
posso dire al computer di aspettare X secondi prima di eseguire
qualcosa, e anche se fosse è comunque una cosa piuttosto scomoda
perché terrei impegnato il processore a... non fare nulla!

Di fatto le soluzioni con la programmazione imperativa sono due:

1. Posso leggere la temperatura ad ogni ciclo di clock

```typescript
while (true) {
  const t = termometro.leggiTemperatura();

  // Salvo la temperatura su file, per semplicità noi
  // la stampiamo solo su terminale
  console.log(t);
}
```

Problema: in pochi secondi il file si riempirebbe di dati (per lo più
tutti uguali) ed esploderebbe in dimensioni.

2. Posso attendere attivamente e poi leggere la temperatura

```typescript
while (true) {
  const t = termometro.leggiTemperatura();

  // Salvo la temperatura su file, per semplicità noi
  // la stampiamo solo su terminale
  console.log(t);

  attendiCircaUnSecondo();
}
```

Problemi: il tempo di attesa dipende dalla velocità del computer e dal
carico del sistema, quindi è molto difficile stabilire quanti cicli di
clock dobbiamo sprecare e questo algoritmo non funziona allo stesso
modo su tutti i computer.

La funzione `attendiCircaUnSecondo` è implementata come un ciclo che
"consuma" tempo CPU senza fare effettivamente nulla.

```typescript
function attendiCircaUnSecondo() {
  let x = 1;
  // attesa attiva
  for (let i = 0; i < 500000000; i++) {
    x = Math.pow(x, i); // cerco di far sprecare tempo alla cpu
  }
}
```

Bisogna trovare un altro sistema. **Cambiamo prospettiva**. E se ci
facessimo dire dal sensore quando viene letta una nuova temperatura?
In questo modo risolveremmo tutti i problemi riscontrati
precedentemente.

Okay ma, cosa significa "farci dire dal sensore quando viene letta una
nuova temperatura"? Beh significa proprio questo, significa farci
mandare un messaggio dal termometro dove viene indicata la
temperatura.

Nel nostro mondo un messaggio potrebbe essere una chiamata a funzione
con un parametro che riceve la temperatura: un **callback**!

In programmazione, un callback è una funzione che viene passata come
parametro ad un'altra funzione. In questo modo la funzione chiamante
può realizzare un compito specifico (quello svolto dalla callback) che
non è, molto spesso, noto al momento della scrittura del codice.

Nell'esempio la nostra callback si limita a stampare a video il valore
della temperatura, ma in realtà potrebbe fare cose ben più sofisticate
come scriverla su file, bufferizzarla e poi scriverla su file, far
partire i caloriferi se questa scende sotto una certa soglia e così
via.

Realizziamo quindi la nostra semplice callback.

```typescript
function notificaTemperatura(temperatura: number) {
  // Salvo la temperatura su file, per semplicità noi
  // la stampiamo solo su terminale
  console.log(temperatura);
}
```

Ora siamo pronti per farci notificare dal sensore la temperatura, ma
il nostro sensore non è progettato per fare questo, dobbiamo ripensare
anche il sensore!

Nell'ottica della programmazione per eventi, possiamo sfruttare la
funzione `setInterval` offerta dalla libreria standard di JavaScript
che permette di eseguire una funzione (un callback!!!) allo scadere di
un certo numero di secondi, ripetutamente.

Sintassi: `setInterval(callback, inteval)`.

```typescript
function ciao() {
  console.log("Ciao Mondo!");
}

setInterval(ciao, 1000);
console.log("Inizio");

// Output:
// Inizio
// Ciao Mondo!   (dopo 1000 ms)
// Ciao Mondo!   (dopo 2000 ms)
// Ciao Mondo!   (dopo 3000 ms)
// ...
```

NB: esiste anche una funzione che esegue un callback allo scadere di X
millisecondi ma una sola volta, ed è `setTimeout`.

Sintassi: `setTimeout(callback, timeout)`.

Sfruttando questo fatto possiamo ora implementare il nostro sensore
fake, ma lo riprogettiamo da zero o possiamo salvare qualcosa?

Se lo volessimo riprogettare da zero potremmo banalmente riscrivere la
funzione `leggiTemperatura` del termometro e pensarla ad eventi:

```typescript
export class Termometro {
  leggiTemperatura(callback: (temperatura: number) => void) {
    const notificaTemperatura = () => {
      const temperatura = Math.random() + 20;

      // Notifichiamo chi ha chiesto la temperatura
      callback(temperatura);

      // Eseguamo di nuovo leggi temperatura così che tra 1000 ms potremo
      // rileggere la temperatura.

      // this.leggiTemperatura(callback);
    };

    setInterval(notificaTemperatura, 1000);
  }
}
```

Ma se la nostra logica fosse molto più complicata? Sfruttiamo al
massimo i callback!

```typescript
import { Termometro } from "./termometro";

export class TermometroNotificatore {
  private termometro: Termometro;
  private callbacks = [];

  constructor(termometro: Termometro) {
    this.termometro = termometro;
    this.leggiTemperatura();
  }

  aggiungiAscoltatore(callback: (temperatura: number) => void) {
    this.callbacks.push(callback);
  }

  leggiTemperatura() {
    const notificaTemperatura = () => {
      const temperatura = this.termometro.leggiTemperatura();

      // Notifichiamo chi ha chiesto la temperatura
      for (const callback of this.callbacks) {
        callback(temperatura);
      }
    };

    setInterval(notificaTemperatura, 1000);
  }
}
```

In questo caso stiamo scrivendo una classe che **non** conosce come il
termometro legge la temperatura (potrebbe farlo, ad esempio, in modo
molto sofisticato con sensori super precisi) ma si occupa solo di
**notificare** la temperatura a chi ha chiesto di essere notificato.
