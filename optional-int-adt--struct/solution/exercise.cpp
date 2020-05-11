#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct optional_int {
    int where;
    int left;
    string right;
};

optional_int make_optional(int x) {
    optional_int o;
    o.where = 0;
    o.left = x;
    return o;
}

optional_int make_optional(string err) {
    optional_int o;
    o.where = 1;
    o.right = err;
    return o;
}

void use(optional_int o) {
    if (o.where == 0) {
        cout << o.left << endl;
    }
    if (o.where == 1) {
        cout << o.right << endl;
    }
}

optional_int search_multiple_3(vector<int> A) {
    for (int a : A) {
        if (a % 3 == 0) return make_optional(a);
    }
    return make_optional("elemento non trovato");
}

int main() {
    optional_int o1 = make_optional(5);
    optional_int o2 = make_optional("test error");

    use(o1);
    use(o2);

    use(search_multiple_3({1, 2, 4, 7}));
    use(search_multiple_3({1, 2, 4, 18, 7}));

    return 0;
}

/** OUTPUT
 * 5
 * test error
 */