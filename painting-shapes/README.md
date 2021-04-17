# Painting Shapes

Si supponga di dover sviluppare un'applicazione per calcolare il
numero di litri di pittura da utilizzare per pitturare degli ogetti
con forme diverse. Le forme supportate sono _sfera_, _rettangolo_ e
_cilindro_.

La richiesta deve essere implementata tramite il polimorfismo
dinamico.

Sviluppare quindi una gerarchia di classi dove `Forma` è la
superclasse e `Sfera`, `Rettangolo` e `Cilindro` sono le derivate.

1. Scrivere una classe `Forma` che abbia le seguenti proprietà.

   - Un campo private che memorizzi il _nome_ della forma di tipo
     `std::string`
   - Un metodo astratto `superifcie` che restituisce un valore con
     virgola rappresentante superficie in $m^2$
   - Un metodo `to_str` che restituisce il nome della forma

2. Scrivere le classi `Sfera`, `Rettangolo` e `Cilindro` utilizzando
   le seguenti formule per il calcolo dell'area.

   - Area della sfera $A_s = 4 * \pi * r^2$ (con $r$ raggio)
   - Area del rettangolo $A_r = b * a$ (con $b$ base e $a$ altezza)
   - Area del cilindo $A_r = \pi * r^2 * a$ (con $r$ raggio e $a$
     altezza)

3. Modificare la classe `Pittura`. La classe consente di calcolare,
   dato il numero di metri quadrati pitturati con 1 litro, la quantià
   di pittura da acquistare per una certa superficie da pitturare.
   Implementare il metodo `quantita` in modo che calcoli quando detto
   sopra.

4. Completare il main con dei test. Istanziare le 3 forme con dei
   valori a piacere e calcolare il numero di litri di pittura da
   acquistare per ogni forma e il totale.

## Allegati

Il codice che segue può essere trovato interamente nel file `main.cpp`
allegato a questo esercizio.

### Classe Pittura

```cpp
class Pittura
{
private:
    double copertura; // quanti metri quadrati sono pitturati con un litro
public:
    Pittura(double copertura)
    {
        this->copertura = copertura;
    }

    double quantita(Forma *forma);  // DA COMPLETARE
};
```

### Main

```cpp
int main()
{
    Pittura acrilica(5);
    Pittura olio(2);

    Forma *sfera;       // DA COMPLETARE: istanziare la sfera
    Forma *rettangolo;  // DA COMPLETARE: istanziare il rettangolo
    Forma *cilindro;    // DA COMPLETARE: istanziare il cilindro

    std::cout << "ACRILICO" << std::endl;
    std::cout << "Forma      \t Quantità" << std::endl;
    std::cout << "-----      \t --------" << std::endl;
    std::cout << "Sfera      \t" << "TODO" << std::endl;  // DA COMPLETARE: sostituire "TODO" con il calcolo vero
    std::cout << "Rettangolo \t" << "TODO" << std::endl;  // DA COMPLETARE
    std::cout << "Cilindro   \t" << "TODO" << std::endl;  // DA COMPLETARE
    std::cout << "-----      \t --------" << std::endl;
    std::cout << "Totale     \t TODO" << std::endl;       // DA COMPLETARE

    std::cout << std::endl << "OLIO" << std::endl;
    std::cout << "Forma      \t Quantità" << std::endl;
    std::cout << "-----      \t --------" << std::endl;
    std::cout << "Sfera      \t" << "TODO" << std::endl;  // DA COMPLETARE
    std::cout << "Rettangolo \t" << "TODO" << std::endl;  // DA COMPLETARE
    std::cout << "Cilindro   \t" << "TODO" << std::endl;  // DA COMPLETARE
    std::cout << "-----      \t --------" << std::endl;
    std::cout << "Totale     \t TODO" << std::endl;       // DA COMPLETARE
}
```
