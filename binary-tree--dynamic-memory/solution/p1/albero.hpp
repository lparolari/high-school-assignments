#include <iostream>
#include <string>

#include "nodo.hpp"

#ifndef ALBERO_HPP
#define ALBERO_HPP

namespace Albero
{
    struct Albero
    {
        Nodo::Nodo *radice;
    };

    Albero *costruisci(Nodo::Nodo *radice)
    {
        Albero *a = new Albero;
        a->radice = radice;
        return a;
    }

    Albero *unisci(Albero *r, Albero *a1, Albero *a2)
    {
        r->radice->sx = a1->radice;
        r->radice->dx = a2->radice;

        return r;
    }

    Nodo::Nodo *radice(Albero *a)
    {
        return a->radice;
    }

    Albero *sx(Albero *a)
    {
        return costruisci(a->radice->sx);
    }

    Albero *dx(Albero *a)
    {
        return costruisci(a->radice->dx);
    }

    void visita_in_profondita_postorder(Albero *a)
    {
        // CASO RICORSIVO: visitare il sottoalbero sinistro, finché può
        // CASO RICORSIVO: visitare il sottoalbero destro, finché può
        // CASO BASE: stampare il valore

        if (a->radice == nullptr)
        {
            std::cout << "[]" << std::endl;
            return;
        }

        if (a->radice->sx != nullptr)
        {
            visita_in_profondita_postorder(sx(a));
        }

        if (a->radice->dx != nullptr)
        {
            visita_in_profondita_postorder(dx(a));
        }

        std::cout << a->radice->valore << std::endl;
    }

}; // namespace Albero

#endif // ALBERO_HPP
