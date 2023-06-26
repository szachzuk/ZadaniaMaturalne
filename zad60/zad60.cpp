#include <bits/stdc++.h>

using namespace std;

int Liczby[200];
vector<vector<int>> Dzielniki;
multiset<int> MS;

void Wczytywanie()
{
    ifstream plik("liczby.txt");

    for (int i = 0; i < 200; i++)
        plik >> Liczby[i];
}

void Zadanie1()
{
    vector<int> l;

    for (int i = 200 - 1; i >= 0; i--)
        if (Liczby[i] < 1000)
            l.push_back(Liczby[i]);

    cout << "Liczb ponizej tysiaca w pliku jest : " << l.size() << endl;
    cout << "Dwie ostatnie to : " << l[0] << " i : " << l[1] << endl;
}

void TworzenieDzielnikow()
{
    vector<int> D;
    for (int i = 0; i < 200; i++)
    {
        for (int j = 1; j <= Liczby[i]; j++)
        {
            if (Liczby[i] % j == 0)
                D.push_back(j);
        }
        Dzielniki.push_back(D);
        D.clear();
    }
}

void Zadanie2()
{
    for (int i = 0; i < 200; i++)
    {
        if (Dzielniki[i].size() == 18)
        {
            cout << Liczby[i] << " ";
            for (int j = 0; j < 18; j++)
            {
                cout << Dzielniki[i][j] << " ";
            }
            cout << endl;
        }
    }
}

bool CzyWzgledniePierwsza(int indeks)
{
    for (int j = 1; j < Dzielniki[indeks].size(); j++)
        if (MS.count(Dzielniki[indeks][j]) != 1)
            return false;

    return true;
}

void Zadanie3()
{
    vector<int> l;
    for (int i = 0; i < 200; i++)
        for (int j = 0; j < Dzielniki[i].size(); j++)
            MS.insert(Dzielniki[i][j]);

    for (int i = 0; i < 200; i++)
        if (CzyWzgledniePierwsza(i))
            l.push_back(Liczby[i]);

    cout << *max_element(l.begin(), l.end()) << endl;
}

int main()
{
    Wczytywanie();
    Zadanie1();
    TworzenieDzielnikow();
    Zadanie2();
    cout << endl;
    Zadanie3();
}