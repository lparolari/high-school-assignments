#include <iostream>

using namespace std;

// Soluzione 1
// ===========
// In questa soluzione si cerca un numero divisibile per tutti i
// numeri tra 1 e 20. Si parte da 1 e si procede con la ricerca.
// Questa soluzione non è efficiente perché esegue un sacco di
// test inutili. Nel caso di 20 esegue la divisione circa
//    20 * 230 milioni
// di volte.
void soluzione1() {
    int n = 1;

    while (true) {
        int i;
        for (i = 1; i <= 20; i++) {
            if (n % i != 0) break;
        }

        if (i - 1 == 20)  // if(trovato) ...
            break;
        else
            n++;
    }

    cout << n << endl;
}

// Soluzione 2
// ===========
// In questa soluzione si calcola il numero cercato semplicemente
// con l'mcm.
void soluzione2() {
    int res = 2 * 3 * 2 * 5 * 7 * 2 * 3 * 11 * 13 * 2 * 17 * 19;
    cout << res << endl;
}

// MAIN
int main() {
    soluzione1();
    cout << "===============" << endl;
    soluzione2();
}
