#ifndef NODO_HPP
#define NODO_HPP

namespace Nodo
{
    struct Nodo
    {
        int valore;
        Nodo *sx;
        Nodo *dx;
    };

    Nodo *costruisci(int valore)
    {
        Nodo *n = new Nodo;
        n->valore = valore;
        n->sx = nullptr;
        n->dx = nullptr;
        return n;
    }

    int valore(Nodo *n)
    {
        return n->valore;
    }

    Nodo *sx(Nodo *n)
    {
        return n->sx;
    }

    Nodo *dx(Nodo *n)
    {
        return n->dx;
    }

}; // namespace Nodo

#endif // NODO_HPP
