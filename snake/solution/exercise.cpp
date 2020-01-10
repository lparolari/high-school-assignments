#include <iostream>

using namespace std;

const int R = 4;
const int C = 4;

// Imposta il valore dell'elemento della matrice `A`
// in posizione `(i,j)` al valore di `c`.
void set(char A[], char c, int i, int j) {
    A[i * C + j] = c;
}

// Restituisce l'elemento in posizione `(i,j)` della matrice `A`.
char get(char A[], int i, int j) {
    return A[i * C + j];
}

// Disegna la matrice `A`.
void disegna(char A[]) {
    for (int i = 0; i < C + 2; i++) cout << "#"
                                         << " ";
    cout << endl;
    for (int i = 0; i < R; i++) {
        cout << "#"
             << " ";
        for (int j = 0; j < C; j++) {
            cout << A[i * C + j] << " ";
        }
        cout << "#" << endl;
    }
    for (int i = 0; i < C + 2; i++) cout << "#"
                                         << " ";
    cout << endl;
}

// Inizializza la matrice `A` con il carattere `c`.
void inizializza(char A[], char c) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            set(A, c, i, j);
        }
    }
}

// **************************************
int main() {
    char A[C * R];

    inizializza(A, ' ');
    set(A, '@', 0, 0);

    // DA FARE: animare la matrice e aggiornarla in base alla
    // direzione in cui l'utente desidera andare

    // Hint: chiedere all'utente la direzione in cui muovere lo snake.
    //       Provare inizialmente muovendo uno snake di lunghezza 1.

    disegna(A);

    return 0;
}