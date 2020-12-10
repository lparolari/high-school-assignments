#include "nodo.hpp"
#include "lista.hpp"

#ifndef CODA_HPP
#define CODA_HPP

namespace Coda
{
    // Struttura dati che rappresenta la lista.
    struct Coda
    {
        Lista::Lista contenitore;
    };

    // ////////////////////////////////////////////////////
    // Prototipi delle funzioni che lavorano sulla coda.

    /** Costruisce una coda vuota. */
    Coda costruisci_vuota();

    /** Inserisce un elemento in fondo alla coda. */
    Coda inserisci(Coda c, int v);

    /** Toglie un elemento dall'inizio della coda. */
    Coda togli(Coda c);

    /** Restituisce un puntatore al primo elemento della coda, se esiste, `nullptr` altrimenti. */
    Nodo::Nodo *primo(Coda c);

    /** Stampa su standard output la rappresentazione della coda in stringa. */
    void stampa(Coda c);

    /** Restituisce la dimensione della coda. */
    int dimensione(Coda c);

    /** Restituisce `true` se la coda è vuota, `false` altrimenti. */
    bool is_vuota(Coda c);

    // ////////////////////////////////////////////////////
    // Implementazione dei prototipi.

    // TODO: Aggiungere implementazioni mancanti qui sotto.

} // namespace Coda

#endif // CODA_HPP