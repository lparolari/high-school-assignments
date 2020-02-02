#include <cstdlib>
#include <iostream>

using namespace std;

int get_rand() {
    return (rand() % 2) == 0 ? -1 : 1;
}

int round(int space, int initial_pos, int step_no) {
    int x = initial_pos;

    for (int i = 0; i < step_no; i++) {
        for (int j = 0; j < x; j++) cout << ".";
        cout << x;
        for (int j = x + 1; j < space; j++) cout << ".";
        cout << endl;

        x = x + get_rand();
        x = x < 0 ? 0 : (x >= step_no ? step_no - 1 : x);
    }

    return x;
}

double avg(int A[], int n) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        s += A[i];
    }
    return s / n;
}

int main() {
    int round_no = 200;

    int space = 15;
    int initial_pos = space / 2 - 1;
    int step_no = 10;

    int results[round_no];

    srand(42);

    for (int i = 0; i < round_no; i++) {
        results[i] = round(space, initial_pos, step_no);
        cout << "***************" << endl;
    }

    cout << "Average = " << avg(results, round_no) << endl;

    return 0;
}