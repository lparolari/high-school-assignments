#ifndef NODO_HPP
#define NODO_HPP

namespace Nodo
{
    // Struttura dati del nodo.
    struct Nodo
    {
        int valore;
        Nodo *prossimo;
    };

    // Prototipi delle funzioni che lavorano su nodi.
    Nodo *costruisci_nodo(int v, Nodo *p);
    int valore(Nodo *n);
    bool esisteProssimo(Nodo *n);
    Nodo *vaiAvanti(Nodo *n);

    // Implementazione dei prototipi.

    Nodo *costruisci_nodo(int v, Nodo *p)
    {
        Nodo *pn = new Nodo;
        pn->valore = v;
        pn->prossimo = p;

        return pn;
    }

    int valore(Nodo *n)
    {
        return n->valore;
    }

    bool esisteProssimo(Nodo *n)
    {
        return !(n->prossimo == nullptr);
    }

    Nodo *vaiAvanti(Nodo *n)
    {
        return n->prossimo;
    }
} // namespace Nodo

#endif // NODO_HPP