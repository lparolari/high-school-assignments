#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Converter {
   public:
    virtual double converti(double input) = 0;
};

class MetroToChilometro : public Converter {
   public:
    double converti(double input) {
        return input / 1000;
    }
};

class MetroToCentimetro : public Converter {
   public:
    double converti(double input) {
        return input * 100;
    }
};

class DoubleConverter : public Converter {
   public:
    double converti(double input) {
        return input * 2;
    }
};

class SquareConverter : public Converter {
   public:
    double converti(double input) {
        return input * input;
    }
};

int main() {
    // Converter* c1 = new MetroToChilometro();
    // Converter* c2 = new MetroToCentimetro();

    // cout << c1->converti(1000) << endl;
    // cout << c2->converti(1000) << endl;

    Converter* d = new DoubleConverter();
    Converter* s = new SquareConverter();

    vector<double> A = {1, 3, 5, 7};
    vector<Converter*> C = {d, s, d, s};

    for (int i = 0; i < 4; i++) {
        Converter* c = C[i];
        double v = A[i];
        cout << c->converti(v) << endl;
    }

    return 0;
}