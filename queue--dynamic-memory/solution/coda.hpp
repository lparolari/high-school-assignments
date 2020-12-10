#include "nodo.hpp"
#include "lista.hpp"

#ifndef CODA_HPP
#define CODA_HPP

namespace Coda
{
    struct Coda
    {
        Lista::Lista contenitore;
    };

    Coda costruisci_vuota()
    {
        Coda c;
        c.contenitore = Lista::costruisci_vuota();
        return c;
    }

    Coda inserisci(Coda c, int v)
    {
        c.contenitore = Lista::inserisci_fondo(c.contenitore, v);
        return c;
    }

    Coda togli(Coda c)
    {
        c.contenitore = Lista::rimuovi_inizio(c.contenitore);
        return c;
    }

    Nodo::Nodo *primo(Coda c)
    {
        return Lista::primo(c.contenitore);
    }

    void stampa(Coda c)
    {
        std::cout << Lista::to_str(c.contenitore) << std::endl;
    }

    int dimensione(Coda c)
    {
        return Lista::dimensione(c.contenitore);
    }

    bool is_vuota(Coda c)
    {
        return Lista::is_vuota(c.contenitore);
    }

} // namespace Coda

#endif // CODA_HPP