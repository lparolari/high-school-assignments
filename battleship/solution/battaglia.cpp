#include <algorithm>
#include <iostream>

using namespace std;

const int M = 10, N = 10;

struct coord {
    int x;
    int y;
};

void init_matrix(char matrix[M][N], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = ' ';
        }
    }
};

void print_matrix(char matrix[M][N], int m, int n) {
    char space = ' ';
    for (int i = 0; i < m + 4; i++) cout << "*" << space;
    cout << endl;
    cout << "*" << space << space << space << space << space;
    for (int i = 0; i < m; i++) cout << (char)('A' + i) << space;
    cout << "*" << endl;

    for (int i = 0; i < m; i++) {
        cout << "*" << space << i + 1 << space << space << (i + 1 < 10 ? space : '\0');
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << space;
        }
        cout << "*";
        cout << endl;
    }

    for (int i = 0; i < m + 4; i++) cout << "*" << space;
    cout << endl;
};

coord ask_coord() {
    char x, y;
    cout << "Coordinata (A-J) (1-10): ";
    cin >> x >> y;
    coord p;
    // TODO: checks
    p.x = (int)(x - 'A');
    p.y = (int)(y - '0' - 1);
    return p;
}

void ask_boat(char matrix[M][N], char boat, int l) {
    cout << "Inserimento nuova barca." << endl;
    for (int i = 0; i < l; i++) {
        coord c = ask_coord();
        // cin >> r;
        // cin >> c;
        matrix[c.x][c.y] = boat;
    }
}

void print_player_turn(int p) {
    cout << "------------------------------------" << endl;
    cout << "PLAYER " << p << endl;
}

main() {
    char p1_board[M][N];
    char p2_board[M][N];

    init_matrix(p1_board, M, N);
    init_matrix(p2_board, M, N);

    // placing boats on G1 board
    print_player_turn(1);
    // print_matrix(p1_board, M, N);
    ask_boat(p1_board, '1', 3);
    // ask_boat(p1_board, '2', 3);
    // ask_boat(p1_board, '3', 3);
    print_matrix(p1_board, M, N);

    // placing boats on G2 board
    print_player_turn(2);
    print_matrix(p2_board, M, N);
    ask_boat(p2_board, '1', 3);
    //ask_boat(p2_board, '2', 4);
    //ask_boat(p2_board, '3', 5);
    print_matrix(p2_board, M, N);

    bool quit = false;

    int i = 1;
    //while (!quit) {
    //char** board;

    // if (i == 1)
    //     board = p2_board;
    // else
    //     board = p1_board;

    // print_player_turn(i);

    // player change
    i = (i % 2) + 1;
    //}
}