#include <iostream>

using namespace std;

class Matrice3x3 {
   private:
    static const int righe = 3;
    static const int colonne = 3;
    int A[righe][colonne];

   public:
    void stampa() {
        for (int i = 0; i < righe; i++) {
            for (int j = 0; j < colonne; j++) {
                cout << A[i][j];
            }
            cout << endl;
        }
    }

    void inserisci(int v, int i, int j) {
        A[i][j] = v;
    }
};

int main() {
    Matrice3x3 m1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m1.inserisci(i * j, i, j);
        }
    }

    m1.stampa();

    return 0;
}