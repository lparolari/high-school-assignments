#include <iostream>
#include <string>
#include <vector>
#include <climits>

#include "nodo.hpp"

#ifndef ALBERO_HPP
#define ALBERO_HPP

namespace Albero
{
    struct Albero
    {
        Nodo::Nodo *radice;
    };

    // *************************************************************
    // PROTOTIPI

    /**
     * Costruisce un albero vuoto.
     */
    Albero *da_vuoto();

    /**
     * Costruisce un albero dato un valore `radice`.
     */
    Albero *da_valore(int radice);

    /**
     * Costruisce un albero dato un nodo `radice`. Se il nodo indicato
     * è null allora viene costruito un albero vuoto.
     */
    Albero *da_nodo(Nodo::Nodo *radice);

    /**
     * Costruisce un albero in modo ordinato da un array.
     */
    Albero *da_array(std::vector<int> dati); // DA IMPLEMENTARE

    /**
     * Controlla che l'albero sia vuoto, se lo è restituisce true,
     * altrimenti false.
     */
    bool is_vuoto(Albero *a);

    /**
     * Restituisce un albero con radice `r` e rispettivamente gli 
     * alberi `a1` e `a2` come figlio sinistro e figlio destro.
     * 
     * Attenzione: r può avere anche dei figli, essi vegnono ignorati.
     * 
     * Esempio:
     * 
     * r:           a1:           a2:
     *       1             5             8
     *     2   3         6   7         9   0
     * 
     * unisci(r, a1, a2):
     *                         1
     *                   5           8
     *                 6   7       9   0
     */
    Albero *unisci(Albero *r, Albero *a1, Albero *a2);

    /**
     * Restituisce il valore della radice dell'albero `a`.
     */
    int radice(Albero *a);

    /**
     * Restituisce il sottoalbero sinistro dell'albero `a`.
     */
    Albero *figlio_sx(Albero *a);

    /**
     * Restituisce il sottoalbero destro dell'albero `a`.
     */
    Albero *figlio_dx(Albero *a);

    /**
     * Effettua la visita in profondità (post-ordine) dell'albero
     * e stampa i valori dei nodi.
     */
    void stampa(Albero *a);

    /**
     * Inserisce un nuovo valore in modo ordinato nell'albero.
     */
    Albero *inserisci(Albero *a, int v);

    int min(Albero *a);

    int max(Albero *a);

    // *************************************************************
    // IMPLEMENTAZIONE

    Albero *da_vuoto()
    {
        Albero *a = new Albero;
        a->radice = nullptr;
        return a;
    }

    Albero *da_valore(int radice)
    {
        Albero *a = da_vuoto();
        a->radice = Nodo::costruisci(radice);
        return a;
    }

    Albero *da_nodo(Nodo::Nodo *radice)
    {
        Albero *a = da_vuoto();

        // `radice` non è un vero nodo :(
        if (radice == nullptr)
            return a;

        a->radice = radice;

        return a;
    }

    Albero *da_array(std::vector<int> dati)
    {
        Albero *a = da_vuoto();

        for (int i = 0; i < dati.size(); i++)
        {
            a = inserisci(a, dati[i]);
        }

        return a;
    }

    Albero *unisci(Albero *r, Albero *a1, Albero *a2)
    {
        // Assegno rispettivamente ai figli sx e dx, le radici dei due alberi a1 e a2
        r->radice->sx = a1->radice;
        r->radice->dx = a2->radice;

        return r;
    }

    int radice(Albero *a)
    {
        return a->radice->valore;
    }

    Albero *figlio_sx(Albero *a)
    {
        return da_nodo(a->radice->sx);
    }

    Albero *figlio_dx(Albero *a)
    {
        return da_nodo(a->radice->dx);
    }

    void stampa(Albero *a)
    {
        // Se l'albero è vuoto significa che `stampa` è stata chiamata su
        // un sottoalbero "insesistente". Non stampo nulla.
        if (is_vuoto(a))
        {
            return;
        }

        // Se l'albero `a` non è vuoto procedo ricorsivamente prima
        // a sinistra e poi a destra.
        stampa(figlio_sx(a));
        stampa(figlio_dx(a));

        // Stampo il valore del nodo quando non posso più procedere in
        // profondità ne verso sinistra ne verso destra.
        std::cout << a->radice->valore << std::endl;
    }

    bool is_vuoto(Albero *a)
    {
        return a->radice == nullptr;
    }

    Albero *inserisci(Albero *a, int v)
    {
        if (is_vuoto(a))
            return da_valore(v);

        // Qui, a non è vuoto!

        if (v <= radice(a))
        {
            // Inserire il nuovo valore `v` nel sottoalbero sinistro di `a`.
            Albero *nuovo_sx = inserisci(figlio_sx(a), v);
            Albero *vecchio_dx = figlio_dx(a);
            return unisci(a, nuovo_sx, vecchio_dx);
        }

        if (v > radice(a))
        {
            // Inserire il nuovo valore `v` nel sottoalbero destro di `a`.
            Albero *nuovo_dx = inserisci(figlio_dx(a), v);
            Albero *vecchio_sx = figlio_sx(a);
            return unisci(a, vecchio_sx, nuovo_dx);
        }

        return a;
    }

    int min(Albero *a)
    {
        // Se l'albero è vuoto restituiamo il MAX per ragioni di
        // desgin della funzione.
        if (is_vuoto(a))
            return INT_MAX;

        // In questo caso l'albero non è vuoto e ho almeno >= 1 nodi nell'albero.
        // Ora ho due casi da verificare per trovare il min:
        //
        //   (1) posso andare più a sinistra rispetto a dove sono
        //       e quindi trovare un valore più piccolo, oppure
        //
        //   (2) non posso andare più a sinistra e quindi anche
        //       scendendo troverei solo valori più grandi
        //       NB: si ricordi come viene costruito l'albero!

        // Caso 2: posso restituire il valore min
        if (is_vuoto(figlio_sx(a)))
        {
            return radice(a);
        }

        // Caso 1: continuo a cercarlo a sinistra
        return min(figlio_sx(a));
    }

}; // namespace Albero

#endif // ALBERO_HPP
