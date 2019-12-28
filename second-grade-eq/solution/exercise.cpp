#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    double delta = pow(b, 2) - 4 * a * c;

    double x1, x2;
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);

    cout << x1 << endl;
    cout << x2 << endl;
}
