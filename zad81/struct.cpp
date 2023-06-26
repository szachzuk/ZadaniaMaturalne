#include <bits/stdc++.h>

using namespace std;

struct Wspolrzedne
{
    int xa;
    int ya;
    int xb;
    int yb;
    int xc;
    int yc;
};

Wspolrzedne W[100];

void Wczytywanie()
{
    ifstream plik("wspolrzedne.txt");

    for (int i = 0; i < 100; i++)
        plik >> W[i].xa >> W[i].ya >> W[i].xb >> W[i].yb >> W[i].xc >> W[i].yc;
}

bool CzyWspolliniowe(Wspolrzedne P)
{
    return (P.xb - P.xa) * (P.yc - P.ya) == (P.xc - P.xa) * (P.yb - P.ya);
}

int main()
{
}