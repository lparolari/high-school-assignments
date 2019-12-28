#include <iostream>

using namespace std;

int main() {
    int g, m, a;

    cout << "Immetti la data: ";
    cin >> g >> m >> a;

    // data valida se il mese è tra 1 e 12
    // se i giorni sono coerenti rispetto al mese

    bool valida = false;

    if (a >= 1900) {
        if (m >= 0 && m <= 12) {
            if (m == 11 || m == 4 || m == 6 || m == 9) {
                if (g >= 0 && g <= 30) {
                    valida = true;
                }
            } else if (m == 2) {
                if (a % 4 == 0 || a % 400 == 0) {
                    if (g >= 0 && g <= 29) {
                        valida = true;
                    }
                } else {
                    if (g >= 0 && g <= 28) {
                        valida = true;
                    }
                }
            } else {
                if (g >= 0 && g <= 31) {
                    valida = true;
                }
            }
        }
    }

    cout << "La data inserita " << (valida ? "è" : "non è") << " corretta." << endl;
}
