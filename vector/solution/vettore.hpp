#include <vector>
#include <iostream>

using namespace std;

class Vettore
{
private:
    std::vector<double> V;

public:
    Vettore(const Vettore &other)
    {
        V = other.V;
    }

    Vettore(std::vector<double> elementi)
    {
        V = elementi;
    }

    Vettore(int n, double x = 0.)
    {
        V.resize(n);

        for (int i = 0; i < n; i++)
        {
            V[i] = x;
        }
    }

    Vettore(double x, double y)
    {
        V.resize(2);
        V[0] = x;
        V[1] = y;
    }

    double operator[](int i) const
    {
        return V[i];
    }

    Vettore somma(const Vettore &other)
    {
        std::vector<double> tmp = std::vector<double>();
        tmp.resize(V.size());

        for (int i = 0; i < V.size(); i++)
        {
            tmp[i] = (*this)[i] + other[i];
        }

        return Vettore(tmp);
    }

    Vettore prodotto(const Vettore &other)
    {
        std::vector<double> tmp;
        tmp.resize(V.size());

        for (int i = 0; i < V.size(); i++)
        {
            tmp[i] = (*this)[i] * other[i];
        }

        return Vettore(tmp);
    }

    void stampa()
    {
        for (int i = 0; i < V.size(); i++)
        {
            cout << V[i] << ", ";
        }
        cout << endl;
    }

    int dimensione()
    {
        return V.size();
    }

    Vettore operator+(const Vettore &other)
    {
        return somma(other);
    }

    Vettore operator*(const Vettore &other)
    {
        return prodotto(other);
    }
};
