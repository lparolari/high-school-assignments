#include <iostream>

using namespace std;

int max(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}

void reverse(int A[], int n, int C[]) {
    for (int i = 0; i < n; i++) {
        C[n - i - 1] = A[i];
    }
}

void sum(int A[], int a, int B[], int b, int C[]) {
    for (int i = 0; i < a; i++) {
        int sum = A[i] + B[i];
        if (sum > 9) {
            C[i] += sum % 10;
            C[i + 1] += 1;
        }
    }
}

void print_number(int A[], int n) {
    int B[n];
    reverse(A, n, B);
    for (int i = 0; i < n; i++) {
        cout << A[i];
    }
    cout << endl;
}

void print(int A[], int n) {
    int B[n];
    reverse(A, n, B);
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << A[i] << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int a = 15;
    int b = 15;
    int c = 16;

    int A[a] = {
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
    };
    int B[b] = {
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
        9,
    };

    int C[c] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    sum(A, a, B, b, C);

    print_number(A, a);
    cout << "+" << endl;
    print_number(B, b);
    cout << "=" << endl;
    print_number(C, c);

    return 0;
}