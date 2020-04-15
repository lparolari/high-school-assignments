#include <iostream>
#include <vector>

using namespace std;
int STANDARD = 0;
int DECI = 1;
int CENTI = 2;
int MILLI = 3;
int DECA = 4;
int ETTO = 5;
int KILO = 6;

double multipliers[] = {1.0, 1000.0, 100., 10., 0.1, 0.01, 0.001};

class Converter {
   private:
    double m;

   public:
    Converter(int to) {
        m = multipliers[to];
    }
    double converti(double input) {
        return input * m;
    }
};

int main() {
    double A[] = {45, 99982, 1, 0.00593, 0.32};

    cout << "CONVERSIONE A CENTI" << endl;
    Converter centi(CENTI);
    for (int i = 0; i < 5; i++) {
        cout << centi.converti(A[i]) << endl;
    }

    cout << "CONVERSIONE A KILO" << endl;
    Converter kilo(KILO);
    for (int i = 0; i < 5; i++) {
        cout << kilo.converti(A[i]) << endl;
    }

    return 0;
}