#include <bits/stdc++.h>

using namespace std;

pair<string, string> Pomiary2[1095], Pomiary4[1095], Pomiary8[1095];
pair<int, int> S1[1095], S2[1095], S3[1095];

int ZamianaNaDziesietny(string liczba, int system)
{
    int l = 0;
    if (liczba[0] == '-')
    {
        for (int i = 1; i < liczba.length(); i++)
            l += int(liczba[liczba.length() - i] - 48) * pow(system, i - 1);
        l = l * -1;
    }
    else
        for (int i = 0; i < liczba.length(); i++)
            l += int(liczba[liczba.length() - 1 - i] - 48) * pow(system, i);
    return l;
}

string ZamianaNaSystem(int l, int system)
{
    if (system == 0 or system == 1)
        return to_string(l);

    int liczba = abs(l);

    string wynik;
    int tem;
    while (liczba > 0)
    {
        tem = liczba % system;
        if (tem >= 10)
            wynik += char(tem + 55);
        else
            wynik += char(tem + 48);
        liczba /= system;
    }
    reverse(wynik.begin(), wynik.end());

    if (l < 0)
        wynik.insert(0, 1, '-');

    return wynik;
}

void Wczytywanie()
{
    ifstream plik1("dane_systemy1.txt");
    ifstream plik2("dane_systemy2.txt");
    ifstream plik3("dane_systemy3.txt");

    string s1, s2;

    for (int i = 0; i < 1095; i++)
    {
        plik1 >> Pomiary2[i].first >> Pomiary2[i].second;
        S1[i].first = ZamianaNaDziesietny(Pomiary2[i].first, 2);
        S1[i].second = ZamianaNaDziesietny(Pomiary2[i].second, 2);
        plik2 >> Pomiary4[i].first >> Pomiary4[i].second;
        S2[i].first = ZamianaNaDziesietny(Pomiary4[i].first, 4);
        S2[i].second = ZamianaNaDziesietny(Pomiary4[i].second, 4);
        plik3 >> Pomiary8[i].first >> Pomiary8[i].second;
        S3[i].first = ZamianaNaDziesietny(Pomiary8[i].first, 8);
        S3[i].second = ZamianaNaDziesietny(Pomiary8[i].second, 8);
    }
}

void Zadanie1()
{
    int min1 = 999999, min2 = 999999, min3 = 999999;
    for (int i = 0; i < 1095; i++)
    {
        if (S1[i].second < min1)
            min1 = S1[i].second;

        if (S2[i].second < min2)
            min2 = S2[i].second;

        if (S3[i].second < min3)
            min3 = S3[i].second;
    }
    cout << "Stacja 1 : " << ZamianaNaSystem(min1, 2) << endl;
    cout << "Stacja 2 : " << ZamianaNaSystem(min2, 2) << endl;
    cout << "Stacja 3 : " << ZamianaNaSystem(min3, 2) << endl;
}

bool CzyPrawidlowe(int indeks)
{
    return S1[indeks].first != (12 + 24 * (indeks)) and S2[indeks].first != (12 + 24 * (indeks)) and S3[indeks].first != (12 + 24 * (indeks));
}

void Zadanie2()
{
    int ilosc = 0;
    for (int i = 0; i < 1095; i++)
        if (CzyPrawidlowe(i))
            ilosc++;

    cout << "Nieprawidlowe zegray na wszystkich stacjach na raz wystąpiły : " << ilosc << " razy" << endl;
}

void Zadanie3()
{
    int ilrekordowych = 0, m1 = 0, m2 = 0, m3 = 0;

    for (int i = 0; i < 1095; i++)
    {
        if (S1[i].second > m1 or S2[i].second > m2 or S3[i].second > m3)
        {
            ilrekordowych++;

            if (S1[i].second > m1)
                m1 = S1[i].second;

            if (S2[i].second > m2)
                m2 = S2[i].second;

            if (S3[i].second > m3)
                m3 = S3[i].second;
        }
    }
    cout << "Dni rekordowych bylo : " << ilrekordowych << endl;
}
void Zadanie4()
{
    int skok, maks = 0;
    float r;
    for (int i = 0; i < 1095; i++)
    {
        for (int j = i + 1; j < 1095; j++)
        {
            r = pow(S1[i].second - S1[j].second, 2);
            skok = ceil(r / abs(j - i));
            if (skok > maks)
                maks = skok;
        }
    }
    cout << "Najwiekszy skok w stacji S1 wynosi : " << maks << endl;
}

int main()
{
    Wczytywanie();
    Zadanie1();
    Zadanie2();
    Zadanie3();
    Zadanie4();
    return 0;
}