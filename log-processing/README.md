# Log Processing

## Consegna

Si supponga di essere un _log manager_ di un datacenter di Google. Un
log manager è colui che ha in carico la raccolta e l'analisi dei dati
tracciati nei messaggi di log (ovvero una registrazione completa di
tutti gli eventi accaduti) dei server.

Il vostro obiettivo è essere il più veloce possibile a trovare log
rilevanti (con errori) tra tutti i log tracciati e comunicarli al team
che gestisce il servizio per la correzione dell'errore.

I log che raccogliete sono semplicemente stringhe di testo senza
struttura, volete quindi creare un algoritmo per ricostruire una
struttura a partire dal testo e filtrare i messaggi importanti.

Ecco un esempio di log

```
2021-02-14T14:22:05.565Z AccountService 1 Tizio: Tentativo di login in corso
2021-02-14T14:22:05.565Z AccountService 1 Tizio: Accesso avvenuto correttamente
2021-02-14T13:01:53.145Z System 2 Root: Utilizzo della memoria elevato
2021-02-14T13:02:30.632Z System 2 Root: Utilizzo della memoria elevato
2021-02-14T13:02:24.565Z System 3 Root: Memoria piena, ucciso il processo con PID 23612
2021-02-14T14:24:31.112Z AccountService 1 Caio: Tentativo di login in corso
2021-02-14T14:24:47.617Z AccountService 2 Caio: Password errata
2021-02-14T14:24:48.512Z YoutubeService 0 Youtube: Video con ID x65fvdss351 richiesto non esistente
2021-02-14T14:24:48.512Z YoutubeService 0 Youtube: Video con ID 696rweta282 richiesto non esistente
2021-02-14T14:24:48.512Z AccountService 2 Caio: Password errata
2021-02-14T14:25:09.323Z AccountService 2 Caio: Password errata
2021-02-14T14:25:45.287Z AccountService 3 Caio: Accesso proibito per 2 ore
2021-02-14T13:53:45.574Z YoutubeService 2 Unknown: Ricevuto un numero di richieste anormale
2021-02-14T13:53:22.123Z YoutubeService 2 Unknown: Ricevuto un numero di richieste anormale
2021-02-14T13:53:24.773Z YoutubeService 3 Unknown: Bloccato IP 75.12.66.123 per elevato numero di richieste
2021-02-14T12:15:42.685Z System 1 Root: Il server verrà riavviato tra 1h per un riavvio programmato
2021-02-14T12:16:11.147Z System 0 Root: Pulizia dei file temporanei
```

I log sono stringhe di testo separati da _a capo_ dove i primi 4
valori, separati da spazio, indicano:

- data e ora in formato ISO,
- nome del servizio che sta effettuando il log,
- livello di rilevanza del log dove 0=debug, 1=info, 2=warning,
  3=error
- utente che ha generato il log

e successivamente, separato da `:` abbiamo il vero messaggio di log.

Il programma che processa i log dovrà suddividere i log, ricostruirne
la struttura, ordinarli per data e filtrare tutti i messaggi non
importanti così da avere sott'occhio solo quelli veramente importanti.

Scaricare il codice allegato a questo documento, contenente una
traccia di implementazione e realizzare la consegna.

> [https://github.com/lparolari/log-processing](https://github.com/lparolari/log-processing)
