#include <bits/stdc++.h>

using namespace std;

pair<float, float> Wiersze[100][3];

void Wczytywanie()
{
    ifstream plik("wspolrzedne.txt");

    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 3; j++)
            plik >> Wiersze[i][j].first >> Wiersze[i][j].second;

    //for (int i = 0; i < 100; i++)
        //Wiersze[i][0].first = Wiersze[i][0].first - 100;
}

bool CzyPierszaCw(int x, int y)
{
    // cout << x << " " << y<<endl;
    return x > 0 and y > 0;
}

void Zadanie1()
{
    int ile = 0, ile_cz = 0;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (CzyPierszaCw(Wiersze[i][j].first, Wiersze[i][j].second))
                ile_cz++;
        }
        if (ile_cz == 3)
            ile++;
        ile_cz = 0;
    }

    cout << "Zadanie1" << endl;
    cout << ile << endl;
}

bool CzyNalezyDoProstej(float a, float b, int x, int y)
{
    return (a * x + b) == y;
}

pair<float, float> ProstaPrzezDwaPunkty(float xa, float ya, float xb, float yb)
{
    if (xa == xb and ya == yb)
        return {0, ya};
    else if (xa == xb)
        return {-100, -100};
    float a, b;
    a = (ya - yb) / (xa - xb);
    b = ya - a * xa;

    return {a, b};
}

bool Wsp(pair<float, float> p1, pair<float, float> p2, pair<float, float> p3)
{
    return (p2.first - p1.first) * (p3.second - p1.second) == (p3.first - p1.first) * (p2.second - p1.second);
}

void Zadanie2()
{
    int ile = 0;

    /*for (int i = 0; i < 100; i++)
        if (CzyNalezyDoProstej(ProstaPrzezDwaPunkty(Wiersze[i][0].first, Wiersze[i][0].second, Wiersze[i][1].first, Wiersze[i][1].second).first, ProstaPrzezDwaPunkty(Wiersze[i][0].first, Wiersze[i][0].second, Wiersze[i][1].first, Wiersze[i][1].second).second, Wiersze[i][2].first, Wiersze[i][2].second))
            ile++;
*/
    cout << "Zadanie2" << endl;
  //  cout << ile << endl;

    int ile_p = 0;

    for (int i = 0; i < 100; i++)
    {
        if (Wsp(Wiersze[i][0], Wiersze[i][1], Wiersze[i][2]))
            ile_p++;
    }

    cout << ile_p<<endl;
}

int main()
{
    Wczytywanie();
    //Zadanie1();
    Zadanie2();

}