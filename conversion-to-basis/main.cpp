#include <iostream>
#include <vector>
#include <functional>

// Vec = vector<int>, è solo un nuovo nome per scrivere meno!
using Vec = std::vector<int>;

/** Rovesca un array. */
Vec rev(Vec v);

/** Restituisce la rappresentazione in string di un array.
 *  Non aggiunge spazi o virgole, stampa tutto attaccato. */
std::string str(Vec v);

/** Stampa a video una rappresentazione dell'array con spazi e virtgole. */
void stampa_vec(Vec v);

/** Converte x  */
Vec base(std::function<Vec(int)> f, int x);

Vec bin(int x);
Vec oct(int x);
Vec dec(int x);
Vec hex(int x);

int main()
{
    std::cout << str(rev(base(bin, 0))) << std::endl;   // 0
    std::cout << str(rev(base(bin, 5))) << std::endl;   // 101
    std::cout << str(rev(base(bin, 8))) << std::endl;   // 100
    std::cout << str(rev(base(bin, 127))) << std::endl; // 1111111
    std::cout << str(rev(base(bin, 255))) << std::endl; // 11111111

    std::cout << str(rev(base(oct, 0))) << std::endl;   // 0
    std::cout << str(rev(base(oct, 5))) << std::endl;   // 5
    std::cout << str(rev(base(oct, 8))) << std::endl;   // 10
    std::cout << str(rev(base(oct, 127))) << std::endl; // 177
    std::cout << str(rev(base(oct, 255))) << std::endl; // 377

    std::cout << str(rev(base(dec, 0))) << std::endl;   // 0
    std::cout << str(rev(base(dec, 5))) << std::endl;   // 5
    std::cout << str(rev(base(dec, 8))) << std::endl;   // 8
    std::cout << str(rev(base(dec, 127))) << std::endl; // 127
    std::cout << str(rev(base(dec, 255))) << std::endl; // 255

    std::cout << str(rev(base(hex, 0))) << std::endl;   // 0
    std::cout << str(rev(base(hex, 5))) << std::endl;   // 5
    std::cout << str(rev(base(hex, 8))) << std::endl;   // 8
    std::cout << str(rev(base(hex, 127))) << std::endl; // 127
    std::cout << str(rev(base(hex, 255))) << std::endl; // 255
}

// Funzioni utili

Vec conv(int b, int x)
{
    Vec c;
    int d = x;

    do
    {
        int r = d % b;
        c.push_back(r);
        d = d / b;
    } while (d != 0);

    return c;
}

Vec bin(int x)
{
    return conv(2, x);
}

Vec oct(int x)
{
    return conv(8, x);
}

Vec dec(int x)
{
    return conv(10, x);
}

Vec hex(int x)
{
    return conv(16, x);
}

Vec base(std::function<Vec(int)> f, int x)
{
    return f(x);
}

Vec rev(Vec v)
{
    Vec r;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        r.push_back(v[i]);
    }
    return r;
}

Vec pad(Vec v)
{
    Vec p;
    for (int i = 0; i < v.size(); i++)
    {
        p.push_back(v[i]);
    }
    for (int i = v.size(); i < 8; i++)
    {
        p.push_back(0);
    }
    return p;
}

std::string str(Vec v)
{
    std::string s = "";
    for (auto e : v)
    {
        if (e == 10)
            s += "A";
        if (e == 11)
            s += "B";
        if (e == 12)
            s += "C";
        if (e == 13)
            s += "D";
        if (e == 14)
            s += "E";
        if (e == 15)
            s += "F";
        else
            s += std::to_string(e);
    }
    return s;
}

void stampa_vec(Vec v)
{
    std::cout << "[ ";
    for (auto e : v)
    {
        std::cout << e << ", ";
    }
    std::cout << "]" << std::endl;
}
