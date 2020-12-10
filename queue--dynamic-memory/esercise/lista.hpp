#include <iostream>
#include "nodo.hpp"

#ifndef LISTA_HPP
#define LISTA_HPP

namespace Lista
{
    // Struttura dati che rappresenta la lista.
    struct Lista
    {
        Nodo::Nodo *testa;
    };

    // ////////////////////////////////////////////////////
    // Prototipi delle funzioni che lavorano sulla lista.

    /**
     * Restituisce `true` se la lista è vuota, ovvero se il puntatore
     * alla testa della lista è il puntatore nullo `nullptr`, altrimenti
     * `false`.
     */
    bool is_vuota(Lista l);

    /**
     * Costruisce una lista vuota, ovvero, il puntatore alla
     * testa della lista è il puntatore nullo `nullptr`.
     */
    Lista costruisci_vuota();

    /**
     * Costruisce una lista a partire da un nodo.
     * Attenzione: il nodo fornito può avere altri nodi successori.
     */
    Lista costruisci_da_nodo(Nodo::Nodo *testa);

    /**
     * Costruisce una lista a partire dagli elementi di un array.
     */
    Lista costruisci_da_array(int A[], int n);

    /**
     * Restituisce una rappresentazione della lista in stringa.
     */
    std::string to_str(Lista l);

    /**
     * Restituisce la dimensione della lista.
     */
    int dimensione(Lista l);

    /**
     * Restituisce una lista la cui testa è il nodo di indice
     * `indice`. Gli indici partono da zero.
     * Attenzione: se l'indice fornito non è tra quelli ammessi,
     * ovvero `indice < 0` oppure `indice > dimensione(l) - 1`
     * allora viene restituita la lista vuota.
     */
    Lista accedi(Lista l, int indice);

    /**
     * Restituisce una lista la cui testa è il nodo contenente
     * il valore `valore`, se esiste, la lista vuota altrimenti.
     */
    Lista cerca(Lista l, int valore);

    /**
     * Inserisce un nodo in fondo alla lista con valore `valore`
     * e restituisce la lista modificata. 
     */
    Lista inserisci_fondo(Lista l, int valore); // DA IMPLEMENTARE

    /**
     * Inserisce un nodo all'inizio della lista con valore
     * `valore` e restituisce la lista modificata. 
     */
    Lista inserisci_inizio(Lista l, int valore); // DA IMPLEMENTARE

    /**
     * Rimuove il primo elemento dalla lista, se esiste, e restituisce
     * una nuova lista la cui testa è il secondo elemento, se esiste.
     * Se non ci sono elementi da togliere, restituisce la lista vuota.
     */
    Lista rimuovi_inizio(Lista l); // DA IMPLEMENTARE

    /**
     * Rimuove l'ultimo elemento dalla lista, se esiste, e 
     * restituisce la lista modificata. 
     * Se non ci sono elementi da togliere, restituisce la 
     * lista vuota.
     */
    Lista rimuovi_fondo(Lista l); // DA IMPLEMENTARE

    /**
     * Restituisce il primo elemento della lista, se esiste,
     * altrimenti il puntatore nullo.
     */
    Nodo::Nodo *primo(Lista l); // DA IMPLEMENTARE

    /**
     * Restituisce l'ultimo elemento della lista, se esiste,
     * altrimenti il puntatore nullo.
     */
    Nodo::Nodo *ultimo(Lista l); // DA IMPLEMENTARE

    // ////////////////////////////////////////////////////
    // Implementazione dei prototipi.

    bool is_vuota(Lista l)
    {
        return l.testa == nullptr;
    }

    Lista costruisci_vuota()
    {
        Lista l;
        l.testa = nullptr;
        return l;
    }

    Lista costruisci_da_nodo(Nodo::Nodo *testa)
    {
        Lista l;
        l.testa = testa;

        return l;
    }

    Lista costruisci_da_array(int A[], int n)
    {
        Lista l;

        Nodo::Nodo *testa = Nodo::costruisci_nodo(A[0], nullptr);
        Nodo::Nodo *n1 = testa;

        for (int i = 0; i < n - 1; i++)
        {
            Nodo::Nodo *n2 = Nodo::costruisci_nodo(A[i + 1], nullptr);
            n1->prossimo = n2;
            n1 = n2;
        }

        l.testa = testa;

        return l;
    }

    std::string to_str(Lista l)
    {
        if (is_vuota(l))
        {
            return "[]";
        }

        Nodo::Nodo *iteratore = l.testa;
        std::string str = "";

        str += "[ ";
        while (true)
        {
            str += std::to_string(Nodo::valore(iteratore)) + ", ";

            if (!Nodo::esisteProssimo(iteratore))
                break;

            iteratore = Nodo::vaiAvanti(iteratore);
        }
        str += " ]";

        return str;
    }

    int dimensione(Lista l)
    {
        if (is_vuota(l))
            return 0;

        int i = 0;
        Nodo::Nodo *iteratore = l.testa;

        while (true)
        {
            i++;

            if (!Nodo::esisteProssimo(iteratore))
                break;

            iteratore = Nodo::vaiAvanti(iteratore);
        }

        return i;
    }

    Lista accedi(Lista l, int indice)
    {
        if (is_vuota(l))
            return l;

        if (indice < 0)
            return costruisci_vuota();

        Nodo::Nodo *iteratore = l.testa;
        int i = 0;

        while (true)
        {
            if (i == indice)
            {
                return costruisci_da_nodo(iteratore);
            }

            if (!Nodo::esisteProssimo(iteratore))
            {
                return costruisci_vuota();
            }

            iteratore = Nodo::vaiAvanti(iteratore);
            i++;
        }
    }

    Lista cerca(Lista l, int valore)
    {
        if (is_vuota(l))
            return l;

        Nodo::Nodo *iteratore = l.testa;

        while (true)
        {
            if (iteratore->valore == valore)
            {
                return costruisci_da_nodo(iteratore);
            }

            if (!Nodo::esisteProssimo(iteratore))
            {
                return costruisci_vuota();
            }

            iteratore = Nodo::vaiAvanti(iteratore);
        }
    }

    // TODO: Aggiungere implementazione mancanti qui sotto.

} // namespace Lista

#endif // LISTA_HPP