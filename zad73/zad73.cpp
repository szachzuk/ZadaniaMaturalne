#include <bits/stdc++.h>

using namespace std;

string Slowa[1876];

void Wczytywanie()
{
    ifstream plik("tekst.txt");

    for (int i = 0; i < 1876; i++)
        plik >> Slowa[i];
}

bool CzyKolejne(string s1)
{
    for (int i = 0; i < s1.length() - 1; i++)
        if (s1[i] == s1[i + 1])
            return true;

    return false;
}

void Zadanie1()
{
    int ile = 0;

    for (int i = 0; i < 1876; i++)
        if (CzyKolejne(Slowa[i]))
            ile++;

    cout << "Zadanie 73.1 " << endl;
    cout << ile << endl;
}

void Zadanie2()
{
    set<char> S;
    multiset<char> MS;

    for (int i = 65; i <= 90; i++)
        S.insert(char(i));

    float ile = 0.0;

    for (int i = 0; i < 1876; i++)
    {
        for (int j = 0; j < Slowa[i].length(); j++)
        {
            // S.insert(Slowa[i][j]);
            MS.insert(Slowa[i][j]);
            ile++;
        }
    }

    for (auto e : S)
    {
        cout << e << " : " << MS.count(e) << " \t";
        cout << fixed << setprecision(2) << MS.count(e) / ile * 100 << endl;
    }
}

bool CzySamogloska(char zn)
{
    return not(string("AEIOUY").find(zn) != string ::npos);
}

int DlPod(string s1)
{
    int dl = 0, maks = 0;

    for (int i = 0; i < s1.length(); i++)
    {
        if (CzySamogloska(s1[i]))
            dl++;
        else
        {
            if (dl > maks)
            {
                maks = dl;
            }
            dl = 0;
        }
    }
    if (dl > maks)
        return dl;
    return maks;
}

void Zadanie3()
{
    int Dl[1876], ile = 0;
    string sl;

    for (int i = 0; i < 1876; i++)
        Dl[i] = DlPod(Slowa[i]);

    int maks = *max_element(Dl, Dl + 1876);

    for (int i = 0; i < 1876; i++)
        if (Dl[i] == maks)
            ile++;

    for (int i = 0; i < 1876; i++)
    {
        if (Dl[i] == maks)
        {
            sl = Slowa[i];
            break;
        }
    }

    cout << "Zadanie 73.3 " << endl;
    cout << maks << " " << ile << " " << sl;
}

int main()
{
    Wczytywanie();
    Zadanie1();
    Zadanie2();
    Zadanie3();
}