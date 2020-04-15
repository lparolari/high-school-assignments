#include <iostream>

using namespace std;

class CriterioBinario {
   private:
    string op;
    int n;
    bool potenzaDi(int x, int y) {
        int t = y;
        for (int i = 1; i < x; i++) {
            if (x == t) return true;
            t = t * y;
        }
        return false;
    }
    bool multiploDi(int x, int y) {
        for (int i = 0; i < y; i++) {
            if (i * y == x) return true;
        }
        return false;
    }

   public:
    CriterioBinario(string op, int n) {
        this->op = op;
        this->n = n;
    }
    bool vale(int m) {
        if (op == "<")
            return n < m;
        if (op == "==")
            return n == m;
        if (op == "potenza")
            return potenzaDi(m, n);
        if (op == "multiplo")
            return multiploDi(m, n);
        return false;
    }
};

int main() {
    CriterioBinario p("potenza", 3);
    cout << (p.vale(9) ? "si" : "no") << endl;
    cout << (p.vale(10) ? "si" : "no") << endl;

    CriterioBinario m("multiplo", 3);
    cout << (p.vale(9) ? "si" : "no") << endl;
    cout << (p.vale(10) ? "si" : "no") << endl;
    return 0;
}