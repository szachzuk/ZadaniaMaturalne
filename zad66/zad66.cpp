#include <bits/stdc++.h>

using namespace std;

struct Trojka
{
    int a;
    int b;
    int c;
};

Trojka Liczby[1000];

void Wczytywanie()
{
    ifstream plik("trojki.txt");

    for (int i = 0; i < 1000; i++)
        plik >> Liczby[i].a >> Liczby[i].b >> Liczby[i].c;
}

int SumaCyfr(int l)
{
    int suma = 0;
    while (l > 0)
    {
        suma += l % 10;
        l /= 10;
    }
    return suma;
}

void Zadanie1()
{
    cout << "Zadanie1" << endl;
    for (int i = 0; i < 1000; i++)
        if (SumaCyfr(Liczby[i].a) + SumaCyfr(Liczby[i].b) == Liczby[i].c)
            cout << Liczby[i].a << " " << Liczby[i].b << " " << Liczby[i].c << endl;
}

bool CzyPierwsze(int l)
{
    if (l == 1)
        return false;

    if (l == 2)
        return true;

    if (l % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(l); i += 2)
        if (l % i == 0)
            return false;

    return true;
}

void Zadanie2()
{
    cout << "Zadanie2" << endl;
    for (int i = 0; i < 1000; i++)
        if (CzyPierwsze(Liczby[i].a) and CzyPierwsze(Liczby[i].b) and Liczby[i].c == Liczby[i].a * Liczby[i].b)
            cout << Liczby[i].a << " " << Liczby[i].b << " " << Liczby[i].c << endl;
}

bool CzyTrojkatProstokatny(int a, int b, int c)
{
    return (a * a + b * b == c * c or b * b + c * c == a * a or a * a + c * c == b * b);
}

void Zadanie3()
{
    cout << "Zadanie3" << endl;
    for (int i = 0; i < 1000 - 1; i++)
    {
        if (CzyTrojkatProstokatny(Liczby[i].a, Liczby[i].b, Liczby[i].c) and CzyTrojkatProstokatny(Liczby[i + 1].a, Liczby[i + 1].b, Liczby[i + 1].c))
        {
            cout << Liczby[i].a << " " << Liczby[i].b << " " << Liczby[i].c << endl;
            cout << Liczby[i + 1].a << " " << Liczby[i + 1].b << " " << Liczby[i + 1].c << endl;
        }
    }
}

bool CzyTrojkat(int a, int b, int c)
{
    return not(a > b + c or b > a + c or c > a + b);
}

void Zadanie4()
{
    int dl = 0, maxdl = 0, il = 0;

    for (int i = 0; i < 1000; i++)
        if (CzyTrojkat(Liczby[i].a, Liczby[i].b, Liczby[i].c))
            il++;

    for (int i = 0; i < 1000 - 1; i++)
    {
        if (CzyTrojkat(Liczby[i].a, Liczby[i].b, Liczby[i].c) and CzyTrojkat(Liczby[i + 1].a, Liczby[i + 1].b, Liczby[i + 1].c))
            dl++;
        else
        {
            if (maxdl < dl)
                maxdl = dl;

            dl = 1;
        }
    }

    cout << il << endl;
    cout << maxdl << endl;
}

int main()
{
    Wczytywanie();
    Zadanie1();
    Zadanie2();
    Zadanie3();
    Zadanie4();
}