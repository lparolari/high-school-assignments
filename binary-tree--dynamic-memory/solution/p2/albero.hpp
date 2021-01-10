#include <iostream>
#include <string>
#include <vector>

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
    // PROTOTIPO

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
    Albero *da_array(std::vector<int> dati);

    /**
     * Controlla che l'albero sia vuoto, se lo è restituisce true,
     * altrimenti false.
     */
    bool is_vuoto(Albero *a);

    /**
     * Restituisce un albero con radice `r` e rispettivamente gli alberi `a1` e `a2`
     * come figlio sinistro e figlio destro.
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
     * Effettua la visita in profondità (post-ordine) dell'albero e stampa
     * i valori dei nodi.
     */
    void stampa(Albero *a);

    /**
     * Inserisce un nuovo valore in modo ordinato nell'albero.
     */
    Albero *inserisci(Albero *a, int v);

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
        // Albero vuoto: dfs è stata chiamata su un sottofiglio che non
        // esiste... stampo un valore che indica "vuoto".
        // Questo caso durante lo svolgimento dell'algoritmo non dovrebbe
        // mai verificarsi, ma è sempre meglio controllare i casi limite.
        // Inoltre, questo caso serve se viene passato in input direttamente
        // un albero vuoto!
        if (a == nullptr || a->radice == nullptr)
        {
            std::cout << "[]" << std::endl;
            return;
        }

        // Procedo in maniera ricorsiva visitando il sottoalbero sinistro.
        if (a->radice->sx != nullptr)
        {
            stampa(figlio_sx(a));
        }

        // Procedo in maniera ricorsiva visitando il sottoalbero destro.
        if (a->radice->dx != nullptr)
        {
            stampa(figlio_dx(a));
        }

        // Stampo il valore del nodo quando non posso più procedere in
        // profondità ne verso sinistra ne verso destra.
        std::cout << a->radice->valore << std::endl;
    }

    Albero *inserisci(Albero *a, int v)
    {
        // Se vuoto, basta che creo un albero con questo valore (facile!)
        if (is_vuoto(a))
        {
            std::cout << v << " = costruisco" << std::endl;
            return da_valore(v);
        }
        // Se non vuoto devo decidere da che parte inserire

        if (v <= radice(a))
        {
            std::cout << v << " <= " << radice(a) << " = vado a sinistra" << std::endl;
            return unisci(a, inserisci(figlio_sx(a), v), figlio_dx(a));
        }

        if (v > radice(a))
        {
            std::cout << v << " > " << radice(a) << " = vado a destra" << std::endl;
            return unisci(a, figlio_sx(a), inserisci(figlio_dx(a), v));
        }

        return a;
    }

    bool is_vuoto(Albero *a)
    {
        return (a->radice == nullptr);
    }

}; // namespace Albero

#endif // ALBERO_HPP
