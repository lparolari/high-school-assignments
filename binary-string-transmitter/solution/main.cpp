#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

/**
 * Return the int representation for a given char.
 * Note: uses the ASCII encoding.
 */
int char_to_int(char c) { return (int)c; }

/**
 * Return the char representation for a given int.
 * Note: uses the ASCII encoding.
 */
char int_to_char(int i) { return (char)i; }

/**
 * Appende all'array A, partendo dalla posizione start, 
 * l'array bin supposto essere lungo 8 bit.
 */
void append(int A[], int bin[], int start) {
    for (int i = 0; i < 8; i++) {
        A[start + i] = bin[i];
    }
}

/**
 * Build a sequence of 8 bits `bin` given a number `x`.
 */
void int_to_bin(int x, int bin[]) {
    // bin must be long at least 8
    for (int i = 7; i >= 0; i--) {
        if (x != 0) {
            bin[i] = x % 2;
            x = x / 2;
        } else {
            bin[i] = 0;
        }
    }
}

/**
 * Return a number representing the binary sequence `bin`.
 */
int bin_to_int(int bin[]) {
    int n = 0;
    for (int i = 0; i < 8; i++) {
        n += pow(2, i) * bin[8 - 1 - i];
    }
    return n;
}

/**
 * Build a sequence of bits `bin` from a sequence of chars `A`.
 */
void encode(char A[], int bin[]) {
    int len = strlen(A);

    // keeps the position on the array bin
    int start = 0;

    for (int i = 0; i < len; i++) {
        // cast the i-th character to an integer
        int x = char_to_int(A[i]);

        // cast the integer to a sequence of bits
        int bin_tmp[8];
        int_to_bin(x, bin_tmp);

        // append the sequence of bits to the result array
        append(bin, bin_tmp, start);
        start += 8;
    }
}

/**
 * Build a sequence of chars `A` from a sequence of bits `bin` long `len`.
 */
void decode(int bin[], int len, char A[]) {
    int bin_tmp[8];

    // index for bin_tmp
    int j = 0;

    // index for A
    int k = 0;

    for (int i = 0; i < len; i++) {
        bin_tmp[j] = bin[i];

        if (j == 8 - 1) {
            int a = bin_to_int(bin_tmp);
            char c = int_to_char(a);
            A[k] = c;

            j = 0;
            k++;
        } else {
            j++;
        }
    }

    A[k] = '\0';
}

/**
 * Print a binary array.
 */
void print_bin(int bin[], int l) {
    // cout << "[";
    for (int i = 0; i < l; i++) {
        cout << bin[i];  // << ", ";
    }
    cout << endl;  // "]" << endl;
}

/**
 * Read a line from standard input and put the result in `C`.
 */
void read_line(char C[]) {
    int i = 0;
    do {
        char c = getchar();
        if (c == '\n') break;
        C[i] = c;
        i++;
    } while (true);
}

/* *******************************************************/
int main() {
    char input[1000] = {'\0'};
    int bin[8000] = {0};
    int l;

    // *********
    cout << "Frase da codificare: ";
    read_line(input);

    l = strlen(input);

    encode(input, bin);
    print_bin(bin, l * 8);

    // **********
    cout << "Frase da decodificare: ";
    read_line(input);

    l = strlen(input);

    for (int i = 0; i < l; i++) {
        bin[i] = input[i] - '0';
    }

    decode(bin, l, input);
    cout << input << endl;

    return 0;
}