# Impiegati

Si supponga di dover sviluppare un'applicazione per stimare il costo
degli impiegati di un'azienda alla fine di ogni mese. L'azienda ha
diversi impiegati, ma non sono tutti assunti con lo stesso contratto.
In particolare troviamo

- il dipendente, il quale percepisce una certa somma (non soggetta a
  variazioni) ogni mese;

- l'impiegato ad ore, per il quale è definita una tariffa oraria e
  alla fine del mese perscepisce _tariffa oraria \* nunero di ore
  lavorate_;

- l'impiegato "con commissioni", per il quale è definita una tariffa
  oraria (come per l'impiegato ad ore) ed un bonus in percentuale che
  l'impiegato percepisce sul totale delle vendite. Ad esempio, se
  l'impiegato ha lavorato 20 ore con una tariffa di 15.0 €/ora ed ha
  venduto merce per un valore di 600 € con un bonus del 20 % sulle
  vendite, percepirà 300 € (20 \* 15.0 €) più 20% di 600 €, ovvero 120
  €. In totale, percepirà 420 €.

Implementare il calcolo del costo dei dipendenti tramite il
polimorfismo dinamico.

Stimare poi il costo dei dipendenti con i seguenti dati:

- Mario Rossi, dipendente, 1450.5 € / mese

- Giovanni Verdi, dipendente, 1220.2 € / mese

- Paolo Bianchi, impiegato ad ore, 15.0 € / ora, questo mese ha
  lavorato 28 ore

- Giacomo Gialli, impiegato ad ore, 7.5 € / ora, questo mese ha
  lavorato 19 ore

- Antonio Arancioni, commissioni, 20.0 € /ora, bonus dell'8 % sulle
  commissioni, ha venduto merce per un totale di 760 € ed ha lavorato
  23 ore
