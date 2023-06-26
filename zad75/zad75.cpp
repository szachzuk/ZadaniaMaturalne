#include <bits/stdc++.h>

using namespace std;

string Slowa[805];

pair<string, string> Sk[5];

void Wczytywanie()
{
    ifstream plik("tekst.txt");
    ifstream plik2("probka.txt");

    for (int i = 0; i < 805; i++)
        plik >> Slowa[i];

    for (int i = 0; i < 5; i++)
        plik2 >> Sk[i].first >> Sk[i].second;
}

bool CzyPierwszaOstatnia(string s, char zn)
{
    return s[0] == zn and s[s.length() - 1] == zn;
}

void Zadanie1()
{
    cout << "Zadanie1" << endl;

    for (int i = 0; i < 805; i++)
        if (CzyPierwszaOstatnia(Slowa[i], 'd'))
            cout << Slowa[i] << endl;
}

string Szyfrowanie(string s, int a, int b)
{
    string kod;
    for (int i = 0; i < s.length(); i++)
    {
        kod.push_back(char(((s[i] - 97) * a + b) % 26 + 97));
        // cout << s[i] - 97 << " ";
        // cout << (s[i] - 97) * a << " ";
        //  << (s[i] - 97) * a + b << " ";
        // cout << (s[i] - 97) * a + b << " ";
        // cout << ((s[i] - 97) * a + b) % 26 << " ";
        // cout << char(((s[i] - 97) * a + b) % 26 + 97) << " ";
    }
    // cout << "\n";
    return kod;
}

void Zadanie2()
{
    cout << "Zadanie2" << endl;
    for (string s : Slowa)
        if (s.length() >= 10)
            cout << Szyfrowanie(s, 5, 2) << endl;
}

char SzyfrowanieZn(char zn, int a, int b)
{
    return char(((zn - 97) * a + b) % 26 + 97);
}

pair<int, int> KluczSzyfrujacy(string slowo, string szyfr)
{
    int ile = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (Szyfrowanie(slowo, i, j) == szyfr)
                return {i, j};

    return {-10, -10};
}

pair<int, int> KluczDeszyfrujacy(string slowo, string szyfr)
{
    int ile = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (Szyfrowanie(szyfr, i, j) == slowo)
                return {i, j};

    return {-10, -10};
}

void Zadanie3()
{
    cout << "Zadanie3" << endl;

    for (pair<string, string> p : Sk)
    {
        cout << "Klucz szyfrujacy wynosi : ";
        cout << "( " << KluczSzyfrujacy(p.first, p.second).first << ", " << KluczSzyfrujacy(p.first, p.second).second << " )" << endl;
        cout << "Klucz deszyfrujacy wynosi : ";
        cout << "( " << KluczDeszyfrujacy(p.first, p.second).first << ", " << KluczDeszyfrujacy(p.first, p.second).second << " )" << endl;
    }
}

int main()
{
    Wczytywanie();
    Zadanie1();
    Zadanie2();
    Zadanie3();
}