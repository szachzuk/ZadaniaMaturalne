#include <bits/stdc++.h>

using namespace std;

string Napisy[1000];

void Wczytywanie()
{
    ifstream plik("ciagi.txt");

    for (int i = 0; i < 1000; i++)
        plik >> Napisy[i];
}

void Zadanie1()
{
    for (int i = 0; i < 1000; i++)
    {
        if (Napisy[i].length() % 2 == 0)
        {
            string w1(Napisy[i].begin(), Napisy[i].begin() + Napisy[i].length() / 2);
            string w2(Napisy[i].begin() + Napisy[i].length() / 2, Napisy[i].end());

            if (w1 == w2)
                cout << Napisy[i] << endl;
        }
    }
}

bool CzyJedynkiObokSiebie(string ciag)
{
    for (int i = 0; i < ciag.length() - 1; i++)
        if (ciag[i] == ciag[i + 1] and ciag[i] == '1')
            return false;

    return true;
}

void Zadanie2()
{
    int ilosc = 0;

    for (int i = 0; i < 1000; i++)
        if (CzyJedynkiObokSiebie(Napisy[i]))
            ilosc++;

    cout << ilosc << endl;
}

int DwojkowyNaDziesietny(string liczba)
{
    int wynik = 0;

    for (int i = liczba.length(); i > 0; i--)
        wynik += int(liczba[i - 1] - 48) * pow(2, liczba.length() - i);

    return wynik;
}

bool CzyPierwsza(int liczba)
{

    if (liczba == 2)
        return true;

    if (liczba == 0 or liczba == 1 or liczba % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(liczba); i += 2)
        if (liczba % i == 0)
            return false;

    return true;
}

bool CzyPolpierwsza(int liczba)
{
    if (liczba % 2 == 0)
    {
        if (CzyPierwsza(liczba / 2))
            return true;
        else
            return false;
    }

    for (int i = 3; i < liczba; i += 2)
    {
        if (liczba % i == 0 and CzyPierwsza(i))
        {
            if (CzyPierwsza(liczba / i))
                return true;
            else
                return false;
        }
    }

    return false;
}
void Zadanie3()
{
    vector<int> l;
    for (int i = 0; i < 1000; i++)
        if(CzyPolpierwsza(DwojkowyNaDziesietny(Napisy[i])))
            l.push_back(DwojkowyNaDziesietny(Napisy[i]));

    cout << "il : " << l.size()<<endl;
    cout << "min : " << *min_element(l.begin(), l.end())<<endl;
    cout << "max : " << *max_element(l.begin(), l.end())<<endl;
}

int main()
{
    Wczytywanie();
    Zadanie1();
    Zadanie2();
    Zadanie3();
}