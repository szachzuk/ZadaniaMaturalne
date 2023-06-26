#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int liczby8[1000];
int liczby10[1000];
int liczby8To10[1000];

void Wczytywanie1()
{
    fstream plik;
    plik.open("liczby1.txt");
    for (int i = 0; i < 1000; i++)
        plik >> liczby8[i];
}

void Wczytywanie2()
{
    fstream plik;
    plik.open("liczby2.txt");
    for (int i = 0; i < 1000; i++)
        plik >> liczby10[i];
}
int OctalToDec(int n)
{
    int liczba = 0, element = 0, i = 0;
    while (n > 0)
    {
        element = n % 10;
        n /= 10;
        liczba += element * pow(8, i);
        i++;
    }
    return liczba;
}

int Dec2Oct(int n)
{
    int liczba = 0, element = 0, i = 0;
    while (n != 0)
    {
        element = n % 8;
        liczba += element * pow(10, i);
        n /= 8;
        i++;
    }
    return liczba;
}

void ZamianaLiczb8()
{
    set<int> Liczby8To10S;
    for (int i = 0; i < 1000; i++)
    {
        liczby8To10[i] = OctalToDec(liczby8[i]);
        Liczby8To10S.insert(liczby8To10[i]);
        // cout<<liczby8To10[i]<<endl;
    }

    int min = *Liczby8To10S.begin();
    int max = *Liczby8To10S.rbegin();
    cout << Dec2Oct(min) << endl;
    cout << Dec2Oct(max) << endl
         << endl;

    for (auto e : Liczby8To10S)
    {
        cout << e << endl;
    }

    /*sort(liczby8To10, liczby8To10 + 1000);
    for(int i = 0; i < 1000; i++)
        cout<<liczby8To10[i]<<endl;*/
}

int main()
{
    Wczytywanie1();
    Wczytywanie2();
    ZamianaLiczb8();
    cout << OctalToDec(1002);

    return 0;
}
