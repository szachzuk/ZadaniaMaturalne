#include <bits/stdc++.h>

using namespace std;

string Osemkowe1[1000], Osemkowe2[1000];

int Dziesietne2[1000], Dziesietne1[1000];

int NaDziesietny(string liczba)
{
    int wynik = 0;
    for (int i = 0; i < liczba.length(); i++)
        wynik += int(liczba[liczba.length() - 1 - i] - 48) * pow(8, i);

    return wynik;
}

string NaOsemkowy(int liczba)
{
    string wynik = "";
    while (liczba > 0)
    {
        wynik += char(liczba % 8 + 48);
        liczba /= 8;
    }

    reverse(wynik.begin(), wynik.end());

    return wynik;
}

void Wczytywanie()
{
    ifstream plik1("liczby1.txt");
    ifstream plik2("liczby2.txt");

    for (int i = 0; i < 1000; i++)
    {
        plik1 >> Osemkowe1[i];
        Dziesietne1[i] = NaDziesietny(Osemkowe1[i]);
        plik2 >> Dziesietne2[i];
        Osemkowe2[i] = NaOsemkowy(Dziesietne2[i]);
    }
}

void Zadanie1()
{
    cout << "Minimalny element : " << NaOsemkowy(*min_element(Dziesietne1, Dziesietne1 + 1000)) << endl;
    cout << "Maksymalny element : " << NaOsemkowy(*max_element(Dziesietne1, Dziesietne1 + 1000)) << endl;
}

void Zadanie2()
{
    int maks = 0, p = 0, maks_p = 0, dl = 1;

    for (int i = 0; i < 999; i++)
    {
        if (Dziesietne2[i] <= Dziesietne2[i + 1])
            dl++;
        else
        {
            if (dl > maks)
            {
                maks = dl;
                maks_p = p;
            }
            p = i + 1;
            dl = 1;
        }
    }
    cout << "Poczatek ciagu : " << Dziesietne2[maks_p] << endl;
    cout << "Dlugosc ciagu : " << maks << endl;
}

void Zadanie3()
{
    int IleTeSame = 0, IleWieksze = 0;

    for (int i = 0; i < 1000; i++)
        if (Dziesietne1[i] == Dziesietne2[i])
            IleTeSame++;

    for (int i = 0; i < 1000; i++)
        if (Dziesietne1[i] > Dziesietne2[i])
            IleWieksze++;

    cout << "Ta sama wartosc maja liczby w : " << IleTeSame << " liniach" << endl;
    cout << "Liczby z pierwszego pliku sa wieksze w : " << IleWieksze << " liniach" << endl;
}

void Zadanie4()
{
    multiset<char> Dziesietne, Osemkowe;
    string l;

    for (int i = 0; i < 1000; i++)
    {
        l = to_string(Dziesietne2[i]);
        for (int j = 0; j < l.length(); j++)
            Dziesietne.insert(l[j]);

        for (int j = 0; j < Osemkowe2[i].length(); j++)
            Osemkowe.insert(Osemkowe2[i][j]);
    }

    set<char> S(Dziesietne.begin(), Dziesietne.end());
    for (auto e : S)
        cout << e << " " << Dziesietne.count(e) << endl;


    cout << "W zapisie dziesietnym wystepuje : " << Dziesietne.count('6') << " szostek" << endl;
    cout << "W zapisie osemkowym wystepuje : " << Osemkowe.count('6') << " szostek" << endl;
}

int main()
{
    Wczytywanie();
    Zadanie1();
    Zadanie2();
    Zadanie3();
    Zadanie4();
}