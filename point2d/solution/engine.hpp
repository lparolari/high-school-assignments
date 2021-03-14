#include <iostream>
#include <vector>

class Engine
{
private:
    std::vector<char> M;
    int righe;
    int colonne;

    void init_board();

public:
    Engine(int righe = 22, int colonne = 40);
    void clear();
    void flush();
    void display();
    void set(int x, int y, char c);
};

/** Crea un engine grafico */
Engine::Engine(int righe, int colonne)
{
    this->righe = righe;
    this->colonne = colonne;

    this->M.reserve(righe * colonne);
    this->init_board();
}

/** Pulisce il terminale */
void Engine::clear()
{
    std::system("clear");
}

/** Pulisce la matrice dai punti disegnati precedentemente */
void Engine::flush()
{
    init_board();
}

/** Mostra la matrice a video */
void Engine::display()
{
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            std::cout << M[(i * colonne) + j];
        }
        std::cout << std::endl;
    }
}

/** Imposta la cella (x,y) con il carattere `c` */
void Engine::set(int x, int y, char c)
{
    if (x < 0 || y < 0 || x > colonne - 1 || y > righe - 1)
    {
        return;
    }
    M[(y * colonne) + x] = c;
}

/** Inizializza la board con spazi vuoti */
void Engine::init_board()
{
    for (int i = 0; i < righe * colonne; i++)
    {
        M[i] = ' ';
    }
}
