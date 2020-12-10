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

    // ////////////////////////////////////////////////////
    // Prototipi delle funzioni che lavorano su nodi.

    /** 
     * Costruisce un nodo dato un valore `v` e il puntatore 
     * ad un prossimo nodo `p`.
     */
    Nodo *costruisci_nodo(int v, Nodo *p);

    /** 
     * Restituisce il valore di un nodo `n`.
     * Attenzione: il metodo *non* controlla che `n` sia un nodo
     * vero e non il puntatore nullo.
     */
    int valore(Nodo *n);

    /**
     * Restituisce `true` se `n->prossimo` non è il puntatore
     * nullo, `false` altrimenti. 
     */
    bool esisteProssimo(Nodo *n);

    /** 
     * Restituisce il prossimo nodo del nodo `n`, se esiste,
     * altrimenti il puntatore nullo `nullptr`.
     */
    Nodo *vaiAvanti(Nodo *n);

    // ////////////////////////////////////////////////////
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