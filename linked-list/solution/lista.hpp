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

    // Prototipi delle funzioni che lavorano sulla lista.
    bool is_vuota(Lista l);
    Lista costruisci_vuota();
    Lista costruisci_da_nodo(Nodo::Nodo *testa);
    Lista costruisci_da_array(int A[], int n);
    std::string to_str(Lista l);
    int dimensione(Lista l);
    Lista accedi(Lista l, int indice);
    Lista cerca(Lista l, int valore);
    Lista inserisci_fondo(Lista l, int valore);
    Lista inserisci_inizio(Lista l, int valore);
    Lista rimuovi_inizio(Lista l);
    Lista rimuovi_fondo(Lista l);
    Nodo::Nodo *primo(Lista l);
    Nodo::Nodo *ultimo(Lista l);

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

        Nodo::Nodo *iteratore = l.testa;
        int i = 0;

        while (true)
        {
            if (i == indice)
            {
                return costruisci_da_nodo(iteratore);
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

    Lista inserisci_fondo(Lista l, int valore)
    {
        Nodo::Nodo *fondo = Nodo::costruisci_nodo(valore, nullptr);

        if (is_vuota(l))
        {
            return costruisci_da_nodo(fondo);
        }

        Nodo::Nodo *iteratore = l.testa;

        while (true)
        {
            if (!Nodo::esisteProssimo(iteratore))
                break;

            iteratore = Nodo::vaiAvanti(iteratore);
        }

        iteratore->prossimo = fondo;

        return l;
    }

    Lista inserisci_inizio(Lista l, int valore)
    {
        Nodo::Nodo *testa = Nodo::costruisci_nodo(valore, nullptr);

        if (is_vuota(l))
        {
            return costruisci_da_nodo(testa);
        }

        testa->prossimo = l.testa;
        l.testa = testa;
        return l;
    }

    Lista rimuovi_inizio(Lista l)
    {
        if (is_vuota(l))
            return l;

        return costruisci_da_nodo(Nodo::vaiAvanti(l.testa));
    }

    Lista rimuovi_fondo(Lista l)
    {
        if (is_vuota(l))
            return l;

        if (dimensione(l) == 1)
        {
            l.testa->prossimo = nullptr;
            return l;
        }

        Nodo::Nodo *i1 = l.testa;
        Nodo::Nodo *i2 = Nodo::vaiAvanti(i1);

        while (true)
        {
            if (!Nodo::esisteProssimo(i2))
                break;

            i1 = Nodo::vaiAvanti(i1);
            i2 = Nodo::vaiAvanti(i2);
        }

        i1->prossimo = nullptr;

        return l;
    }

    Nodo::Nodo *primo(Lista l)
    {
        if (is_vuota(l))
            return nullptr;

        return l.testa;
    }

    Nodo::Nodo *ultimo(Lista l)
    {
        if (is_vuota(l))
            return nullptr;

        return accedi(l, dimensione(l) - 1).testa;
    }

} // namespace Lista

#endif // LISTA_HPP