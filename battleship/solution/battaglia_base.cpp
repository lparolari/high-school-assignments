#include <algorithm>
#include <iostream>

using namespace std;

// M righe, N colonne
const int M = 10, N = 10;

/**
 * Inizializza la matrice `matrix` con un carattere che rappresenta "il mare".
 */
void init_matrix(char matrix[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = ' ';
        }
    }
};

/**
 * Stampa la matrice `matrix`.
 */
void print_matrix(char matrix[M][N]) {
    char space = ' ';
    for (int i = 0; i < M + 4; i++) cout << "*" << space;
    cout << endl;
    cout << "*" << space << space << space << space << space;
    for (int i = 0; i < M; i++) cout << (char)('A' + i) << space;
    cout << "*" << endl;

    for (int i = 0; i < M; i++) {
        cout << "*" << space << i + 1 << space << space << (i + 1 < 10 ? space : '\0');
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << space;
        }
        cout << "*";
        cout << endl;
    }

    for (int i = 0; i < M + 4; i++) cout << "*" << space;
    cout << endl;
}

/**
 * Chiede le coordinate della barca rappresentata dal carattere `boat`, 
 * lunga `l` e la piazza sulla matrice `matrix`.
 */
void ask_boat(char matrix[M][N], char boat, int l) {}

/**
 * Set a character `x` on `matrix` if `(i, j)` are coordinates for a boat on `matrix`,
 * set an `o` instead.
 */
void hit(char matrix[M][N], int i, int j) {}

/**
 * Returns true if `matrix` does not contain a boat (i.e., a character from 1 to 9).
 */
bool check(char matrix[M][N]) {
    // TODO
    return true;
}

/**
 * Stampa il giocatore che deve giocare.
 */
void print_player_turn(int p) {
    cout << "---------------------------" << endl;
    cout << "PLAYER " << p << endl;
}

// MAIN
main() {
    char p1_board[M][N];
    char p2_board[M][N];

    init_matrix(p1_board);
    init_matrix(p2_board);

    // placing boats on P1 board
    print_player_turn(1);
    ask_boat(p1_board, '1', 3);
    ask_boat(p1_board, '2', 3);
    ask_boat(p1_board, '3', 3);
    print_matrix(p1_board);

    // placing boats on P2 board
    print_player_turn(2);
    ask_boat(p2_board, '1', 3);
    ask_boat(p2_board, '2', 3);
    ask_boat(p2_board, '3', 3);
    print_matrix(p2_board);

    cout << "---------------------------" << endl;
    cout << "---------------------------" << endl;
    cout << "Ready, steady, go!" << endl;

    // the player 1 starts.
    int i = 1;

    while (true) {
        print_player_turn(i);
        if (i == 1) {
            // chedere al giocatore 1 le coordinate da colpire su p2_board
            int x, y;
            // leggere x e y
            hit(p2_board, x, y);
            if (check(p2_board)) {
                cout << "Player 1 wins!";
                break;
            }
        } else if (i == 2) {
            // chedere al giocatore 2 le coordinate da colpire su p1_board
            int x, y;
            // leggere x e y
            hit(p1_board, x, y);
            if (check(p1_board)) {
                cout << "Player 2 wins!";
                break;
            }
        }

        // player change
        i = (i % 2) + 1;
    }

    cout << endl;
}