#include <iostream>

int min(int a, int b) { return (a < b ? a : b); }

void lowest_terms(int &a, int &b)
{
    int m = min(a, b);

    for (int i = 1; i <= m; i++)
    {
        if (!(a % i == 0 && b % i == 0))
            continue;

        a = a / i;
        b = b / i;
    }
}

int main()
{
    int a, b;

    a = 1;
    b = 2;

    std::cout << "lowest_terms(" << a << ", " << b << ") = ";
    lowest_terms(a, b);
    std::cout << a << " / " << b << std::endl;

    a = 4;
    b = 8;

    std::cout << "lowest_terms(" << a << ", " << b << ") = ";
    lowest_terms(a, b);
    std::cout << a << " / " << b << std::endl;

    a = 0;
    b = 1;

    std::cout << "lowest_terms(" << a << ", " << b << ") = ";
    lowest_terms(a, b);
    std::cout << a << " / " << b << std::endl;
}
