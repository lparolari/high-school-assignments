#include <iostream>
#include <vector>

using namespace std;

const int N = 10;

struct queue {
    vector<int> vec;
};

void enqueue(queue& Q, int x) {
    Q.vec.push_back(x);
}

int dequeue(queue& Q) {
    Q.vec.if (Q.i != Q.j) {
        int i = Q.i;
        Q.i = (Q.i + 1) % N;
        return Q.vec[i];
    }
}

int main() {
    queue q1;

    // for (int i = 0; i < 15; i++)
    //     enqueue(q1, i + 1);

    // cout << dequeue(q1) << endl;
    // cout << dequeue(q1) << endl;
    // cout << dequeue(q1) << endl;
    // cout << dequeue(q1) << endl;
    // cout << dequeue(q1) << endl;
    // cout << dequeue(q1) << endl;
    // cout << dequeue(q1) << endl;
    // cout << dequeue(q1) << endl;
    // cout << dequeue(q1) << endl;
    // cout << dequeue(q1) << endl;
    // cout << dequeue(q1) << endl;
    // enqueue(q1, 45);
    // cout << dequeue(q1) << endl;
    // cout << dequeue(q1) << endl;

    return 0;
}