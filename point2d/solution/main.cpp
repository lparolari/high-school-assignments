#include <iostream>
#include <chrono>
#include <thread>
#include "vettore.hpp"
#include "engine.hpp"

int main()
{
    // creo l'engine che ha il compito di visualizzare coordiante 2D
    // con 5 righe e 80 colonne
    Engine engine = Engine(5, 80);

    // creo tre vettori per la simulazione
    Vettore pallina = Vettore(70., 2.);
    Vettore velocita = Vettore(-1., 0.);
    Vettore accelerazione = Vettore(-1., 0.);
    Vettore frizione = Vettore(2, 0.9);

    // inizio la simulazione
    while (true)
    {
        engine.clear();
        engine.flush();

        // disegno il pavimento
        engine.set(0, 0, '|');
        engine.set(0, 1, '|');
        engine.set(0, 2, '|');
        engine.set(0, 3, '|');
        engine.set(0, 4, '|');

        // ricavo le componenti della pallina
        int x_pallina = (int)pallina[0];
        int y_pallina = (int)pallina[1];

        // disegno la pallina
        engine.set(x_pallina, y_pallina, '*');

        // visualizzo tutto a video
        engine.display();

        // attendo 200 ms prima di procedere (5 frame per secondo!)
        // bisogna attendere altrimenti l'occhio umano potrebbe non
        // percepisce il movimento se eseguito troppo velocemente
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        // aggiorno lo stato della pallina
        velocita = velocita + accelerazione;
        pallina = pallina + velocita;

        // quando la pallina tocca il terreno la faccio rimbalzare, ovvero
        // ribalto la sua velocità
        if (pallina[0] <= 0 && velocita[0] <= 0)
        {
            Vettore inverti = Vettore(2, -1.0);

            // la pallina ogni volta che tocca terra è frenata con una certa frizione
            velocita = velocita * inverti * frizione;

            // aggiusto la posizione della pallina dato che potrebbe esssere
            // uscita dallo schermo
            pallina = pallina + velocita;
        }
    }
}
