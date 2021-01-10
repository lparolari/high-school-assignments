#include <iostream>
#include <string>
#include "Nodo.hpp"

#ifndef ALBERO_HPP
#define ALBERO_HPP

namespace Albero
{
    struct Albero
    {
        Nodo::Nodo *radice;
    };

    Albero *costruisci()
    {
        Albero *a = new Albero;
        a->radice = nullptr;

        return a;
    }

    Albero *costruisci(Nodo::Nodo *r)
    {
        Albero *a = new Albero;
        a->radice = r;

        return a;
    }

    Albero *unisci(Albero *r, Albero *sx, Albero *dx)
    {
        r->radice->sx = sx->radice;
        r->radice->dx = dx->radice;

        return r;
    }

    Nodo::Nodo *radice(Albero *a) { return a->radice; }

    Albero *sx(Albero *a) { return costruisci(a->radice->sx); }

    Albero *dx(Albero *a) { return costruisci(a->radice->dx); }

    std::string _to_str_dfs_preorder(Albero *a)
    {
        if (a->radice == nullptr)
            return "";

        std::string s = "";

        s += std::to_string(Nodo::valore(radice(a)));
        // std::cout << s << std::endl;
        s += ", ";

        if (!Nodo::is_null(radice(sx(a))))
            s += _to_str_dfs_preorder(sx(a));

        if (!Nodo::is_null(radice(dx(a))))
            s += _to_str_dfs_preorder(dx(a));

        return s;
    }

    // Effettua una una vistia depth-first in modalità preordine
    std::string to_str(Albero *a)
    {
        std::string ris = "[ ";

        ris += _to_str_dfs_preorder(a);

        ris += " ]";

        return ris;
    }

}; // namespace Albero

#endif // ALBERO_HPP
