template <typename T>
class SmartPointer
{
private:
    // Puntatore alla risorsa da gestire
    T *_pt = nullptr;
    // Puntatore ad un int che rappresenta il numero di riferimenti
    // che puntano alla risorsa gestita. Questa variabile è gestita
    // tramite memoria dinamica perché si ha bisogno che sia condivisa
    // tra tutti gli smart pointer che usano la risorsa.
    int *_ref_number = nullptr;

public:
    // Crea un nuovo smart pointer memorizzando il puntatore ad una
    // risorsa e imposta ad 1 il numero di reference che puntano ad
    // essa.
    SmartPointer(T *pt);

    // Copia `other` nell'oggetto this. Provoca l'incremento del
    //  numero di reference che puntano alla risorsa.
    SmartPointer(const SmartPointer &other);

    // Assegna `other` all'oggetto this. Provoca l'incremento del
    // numero di reference che puntano alla risorsa.
    SmartPointer &operator=(const SmartPointer &other);

    // Distruttore. Dealloca le risorse se `num_ref()` è minore
    //  o uguale a 1.
    ~SmartPointer();

    // Restituisce il numero di reference che puntano alla risorsa.
    int num_ref();

    // Restiuisce il puntatore alla risorsa interna.
    T *get();
};
