#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Matrix {
    ////////////////////////////////////
    // METODI PRIVATI
   private:
    int r;  // righe
    int c;  // colonne
    vector<int> data;

    // Nota: per motivi progettuali è stato scelto di non
    // permettere la modifica della matrice interna.

    // Restituisce l'elemento in posizione i,j.
    int get(int i, int j) {
        return data[i * c + j];
    }

    ////////////////////////////////////
    // METODI PUBBLICI
   public:
    // Crea una matrice date solamente le dimensioni.
    Matrix(int rows, int cols) {
        r = rows;
        c = cols;
    }

    // Crea una matrice data le righe, le colonne e i dati della matrice.
    Matrix(int rows, int cols, vector<int> linearized_data) {
        r = rows;
        c = cols;
        data = linearized_data;
    }

    // Restituisce la matrice sottoforma di stringa.
    string to_string() {
        string res = "";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res += std::to_string(get(i, j)) + " ";
            }
            res += '\n';
        }
        return res;
    }

    // Restituisce la matrice trasposta con nuova dimensione su righe e colonne.
    Matrix reshape(int rows, int cols) {
        // cosa succede se
        //   rows*cols != r*c
        // dobbiamo controllare questo caso?

        return Matrix(rows, cols, data);
    }

    // Restituisce la matrice trasposta.
    Matrix transpose() {
        vector<int> A;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                A.push_back(get(j, i));
            }
        }

        return Matrix(c, r, A);
    }

    // Restituisce una matrice tutta di zeri.
    Matrix zeroes() {
        vector<int> A;
        for (int i = 0; i < r * c; i++) A.push_back(0);
        return Matrix(r, c, A);
    }

    // Restituisce una matrice fatta di interi da 0 a r*c.
    Matrix ints() {
        vector<int> A;
        for (int i = 0; i < r * c; i++) A.push_back(i);
        return Matrix(r, c, A);
    }

    // Restituisce una matrice con valori random tra 0 e 9.
    Matrix randoms() {
        vector<int> A;
        for (int i = 0; i < r * c; i++) A.push_back(rand() % 10);
        return Matrix(r, c, A);
    }

    // Somma due matrici.
    Matrix sum(Matrix y) {
        vector<int> S;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                S.push_back(get(i, j) + y.get(i, j));
            }
        }
        return Matrix(r, c, S);
    }
};

int main() {
    // random seed (dovrebbe essere impostato nella matrice?)
    srand(0);

    Matrix m1(4, 4);
    cout << "m1', dimensione: 4x4, valori: 0" << endl;
    cout << m1.zeroes().to_string() << endl;
    cout << "m1'', dimensione: 2x8, valori: 0" << endl;
    cout << m1.zeroes().reshape(2, 8).to_string() << endl;
    cout << "m1''', dimensione: 8x2, valori: 0" << endl;
    cout << m1.zeroes().reshape(8, 2).to_string() << endl;
    cout << endl;

    Matrix m2(4, 4);
    cout << "m2', dimensione: 4x4, valori: da 0 a 4*4" << endl;
    cout << m2.ints().to_string() << endl;
    cout << "m2'', dimensione: 4x4, valori: da 0 a 4x4, trasposta" << endl;
    cout << m2.ints().transpose().to_string() << endl;
    cout << endl;

    Matrix m3(3, 3);
    cout << "m3', dimensione: 3x3, valori: da 0 a 3*3" << endl;
    cout << m3.ints().to_string() << endl;
    cout << "m3'', dimensione: 3x3, valori: m3' + m3'" << endl;
    cout << m3.ints().sum(m3.ints()).to_string() << endl;
    return 0;
}