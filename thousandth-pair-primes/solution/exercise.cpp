#include <chrono>
#include <iostream>

using namespace std;

bool prime(int n) {
    // n è primo se divisibile solo per 1 e n.
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// La funzione ricerca la n-esima coppia di numeri primi distanti
// solo di un numero.
int findClosestPrime(int n) {
    int m1 = 2;
    int m2 = 4;
    int cont = 0;

    while (cont < 1000) {
        // ho trovato una coppia di numeri primi distante di un solo numero
        if (prime(m1) && prime(m2)) cont++;

        m1++;
        m2++;
    }

    // restituisco il numero primo che avevo trovato
    return m1 - 1;
}

int main() {
    int N = 100;

    // tempo di inizio
    auto start = std::chrono::system_clock::now();

    // chiamo la funzione che cerca l'N-esima coppia
    int m = findClosestPrime(N);

    // tempo di fine
    auto end = std::chrono::system_clock::now();

    // calcolo del tempo impiegato
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    // stampo risultato
    cout << m << " " << m + 2 << endl;
    std::cout << "Tempo impiegato: " << elapsed_seconds.count() << "s\n";

    return 0;
}