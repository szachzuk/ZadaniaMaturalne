#include <bits/stdc++.h>

using namespace std;

pair<string, string> Napisy[200];

void Wczytywanie()
{
    ifstream plik("napisy.txt");

    for (int i = 0; i < 200; i++)
        plik >> Napisy[i].first >> Napisy[i].second;
}

bool CzyDluzszy(string s1, string s2)
{
    return s1.length() >= 3 * s2.length() or 3 * s1.length() <= s2.length();
}

void Zadanie1()
{
    cout << "Zadanie 72.1 ";
    int ile = 0;

    for (int i = 0; i < 200; i++)
    {
        if (CzyDluzszy(Napisy[i].first, Napisy[i].second))
        {
            cout << Napisy[i].first << " " << Napisy[i].second<<" ";
            break;
        }
    }

    for (int i = 0; i < 200; i++)
        if (CzyDluzszy(Napisy[i].first, Napisy[i].second))
            ile++;

    cout << ile << endl;
}

bool CzyDopisanie(string s1, string s2)
{
    for (int i = 0; i < s1.length(); i++)
        if (s2[i] != s1[i])
            return false;

    return true;
}

void Zadanie2()
{
    cout << "Zadanie72.2 ";
    for (int i = 0; i < 200; i++)
    {
        if (CzyDopisanie(Napisy[i].first, Napisy[i].second))
        {
            cout << Napisy[i].first << " " << Napisy[i].second << " ";
            for (int j = Napisy[i].first.length(); j < Napisy[i].second.length(); j++)
            {
                cout << Napisy[i].second[j];
            }
            cout << endl;
        }
    }
}

int DlZak(string s1, string s2)
{
    int ile = 0, w;

    w = s1.length() > s2.length() ? s2.length() : s1.length();
    for (int i = 1; i <= w; i++)
        if (s1[s1.length() - i] == s2[s2.length() - i])
            ile++;
        else
            break;

    return ile;
}

void Zadanie3()
{
    cout << "Zadanie 72.3 ";
    int Dl[200];

    for (int i = 0; i < 200; i++)
        Dl[i] = DlZak(Napisy[i].first, Napisy[i].second);

    int maks = *max_element(Dl, Dl + 200);

    cout << maks << endl;

    for (int i = 0; i < 200; i++)
        if (Dl[i] == maks)
            cout << Napisy[i].first << " " << Napisy[i].second << endl;
}

int main()
{
    Wczytywanie();
    Zadanie1();
    Zadanie2();
    Zadanie3();
}