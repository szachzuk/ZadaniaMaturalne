#include <bits/stdc++.h>

using namespace std;

string Hasla[200];

vector<string> Wystapily;

void Wczytywanie()
{
    ifstream plik("hasla.txt");

    for (int i = 0; i < 200; i++)
        plik >> Hasla[i];
}

bool CzyCyfra(char zn)
{
    return zn >= 48 and zn <= 58;
}

bool CzyTylkoCyfra(string s)
{
    int ile = 0;
    for (int i = 0; i < s.length(); i++)
        if (CzyCyfra(s[i]))
            ile++;

    return s.length() == ile;
}

void Zadanie1()
{
    int ile = 0;
    for (int i = 0; i < 200; i++)
        if (CzyTylkoCyfra(Hasla[i]))
            ile++;

    cout << "Zadanie1" << endl;
    cout << ile << endl;
}

bool CzyJest(string s)
{
    return find(Wystapily.begin(), Wystapily.end(), s) != Wystapily.end();
}

void Zadanie2()
{
    cout << "Zadanie2" << endl;
    for (int i = 0; i < 200; i++)
    {
        if (CzyJest(Hasla[i]))
            cout << Hasla[i] << endl;
        else
            Wystapily.push_back(Hasla[i]);
    }
}

bool CzyKolejne(char zn1, char zn2, char zn3, char zn4)
{
    char Tab[4] = {zn1, zn2, zn3, zn4};
    sort(Tab, Tab + 4);

    return Tab[0] + 1 == Tab[1] and Tab[1] + 1 == Tab[2] and Tab[2] + 1 == Tab[3];
}

void Zadanie3()
{
    int ile = 0;
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < Hasla[i].length() - 3; j++)
        {
            if (CzyKolejne(Hasla[i][j], Hasla[i][j + 1], Hasla[i][j + 2], Hasla[i][j + 3]))
            {
                ile++;
                // char Tab[4] = {Hasla[i][j], Hasla[i][j + 1], Hasla[i][j + 2], Hasla[i][j + 3]};
                // sort(Tab, Tab + 4);
                // cout << Tab[0] << " " << Tab[1] << " " << Tab[2] <<" "<< Tab[3] << endl;
                break;
            }
        }
    }
    cout << "Zadanie3" << endl;
    cout << ile << endl;
}

bool CzyMaCyfre(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] >= 48 and s[i] <= 57)
            return true;

    return false;
}

bool CzyMaMala(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] >= 'a' and s[i] <= 'z')
            return true;

    return false;
}

bool CzyMaDuza(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (s[i] >= 'A' and s[i] <= 'Z')
            return true;

    return false;
}

void Zadanie4()
{
    int ile = 0;

    for (int i = 0; i < 200; i++)
        if (CzyMaCyfre(Hasla[i]) and CzyMaMala(Hasla[i]) and CzyMaDuza(Hasla[i]))
            ile++;

    cout << "Zadanie4" << endl;
    cout << ile << endl;
}

int main()
{
    Wczytywanie();
    Zadanie1();
    Zadanie2();
    Zadanie3();
    Zadanie4();
}