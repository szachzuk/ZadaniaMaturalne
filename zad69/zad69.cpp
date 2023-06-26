#include <bits/stdc++.h>

using namespace std;

vector<string> Dane, DaneR;

vector<vector<string>> Geny, GenyR;

void Wczytywanie()
{
    ifstream plik("dane_geny.txt");

    string d;
    for (int i = 0; i < 1000; i++)
    {
        plik >> d;
        Dane.push_back(d);
    }
}

void Zadanie1()
{
    multiset<int> MS;

    vector<int> ile;

    for (int i = 0; i < 1000; i++)
    {
        MS.insert(Dane[i].length());
    }

    set<int> S(MS.begin(), MS.end());

    for (auto e : S)
    {
        ile.push_back(MS.count(e));
    }

    cout << "Wszystkich gatunkow jest : " << S.size() << endl;
    cout << "Najwieksza liczba osobnikow reprezentujacych ten sam gatunek : " << *max_element(ile.begin(), ile.end()) << endl;
}

void TworzenieGenow()
{
    bool CzyGen = false;
    vector<string> gen;
    string mozliwy_gen;

    for (int i = 0; i < Dane.size(); i++)
    {

        for (int j = 0; j < Dane[i].length() - 1; j++)
        {
            if (Dane[i][j] == 'A' and Dane[i][j + 1] == 'A' and CzyGen == false)
            {
                CzyGen = true;
                mozliwy_gen += "AA";
                j++;
            }
            else if (Dane[i][j] == 'B' and Dane[i][j + 1] == 'B' and CzyGen == true)
            {
                CzyGen = false;
                mozliwy_gen += "BB";
                gen.push_back(mozliwy_gen);
                mozliwy_gen = "";
                j++;
            }
            else if (CzyGen)
                mozliwy_gen += (Dane[i][j]);
        }
        Geny.push_back(gen);
        gen.clear();
        mozliwy_gen = "";
        CzyGen = false;
    }
}

void TworzenieGenowR()
{
    bool CzyGen = false;
    vector<string> gen;
    string mozliwy_gen;

    for (int i = 0; i < DaneR.size(); i++)
    {
        for (int j = 0; j < DaneR[i].length() - 1; j++)
        {
            if (DaneR[i][j] == 'A' and DaneR[i][j + 1] == 'A' and CzyGen == false)
            {
                CzyGen = true;
                mozliwy_gen += "AA";
                j++;
            }
            else if (DaneR[i][j] == 'B' and DaneR[i][j + 1] == 'B' and CzyGen == true)
            {
                CzyGen = false;
                mozliwy_gen += "BB";
                gen.push_back(mozliwy_gen);
                mozliwy_gen = "";
                j++;
            }
            else if (CzyGen)
                mozliwy_gen += (DaneR[i][j]);
        }
        GenyR.push_back(gen);
        gen.clear();
        mozliwy_gen = "";
        CzyGen = false;
    }
}

void Zadanie2()
{
    int ilezmeczonych = 0;
    for (int i = 0; i < Geny.size(); i++)
        for (int j = 0; j < Geny[i].size(); j++)
            for (int k = 0; k < Geny[i][j].length() - 4; k++)
                if (Geny[i][j][k] == 'B' and Geny[i][j][k + 1] == 'C' and Geny[i][j][k + 2] == 'D' and Geny[i][j][k + 3] == 'D' and Geny[i][j][k + 4] == 'C')
                    ilezmeczonych++;

    cout << "Liczba mutacji zmeczonych genow wynosi : " << ilezmeczonych << endl;
}

void Zadanie3()
{
    int maksgenow = 0, maksdl = 0;

    for (int i = 0; i < Geny.size(); i++)
    {
        if (Geny[i].size() > maksgenow)
            maksgenow = Geny[i].size();

        for (int j = 0; j < Geny[i].size(); j++)
            if (Geny[i][j].length() > maksdl)
                maksdl = Geny[i][j].length();
    }

    cout << "Najwieksza liczba genow to : " << maksgenow << endl;
    cout << "Najdluzszy gen ma : " << maksdl << endl;
}

bool CzyPalindrom(string n)
{
    string n1 = n;
    reverse(n.begin(), n.end());
    return n1 == n;
}

void Zadanie4()
{
    int ileSilnieOpornych = 0;
    for (int i = 0; i < Dane.size(); i++)
        if (CzyPalindrom(Dane[i]))
            ileSilnieOpornych++;

    cout << "Genow silnie opornych jest : " << ileSilnieOpornych << endl;

    DaneR = Dane;
    for (int i = 0; i < DaneR.size(); i++)
        reverse(DaneR[i].begin(), DaneR[i].end());

    TworzenieGenowR();

    int ileOpornych = 0, tem = 0;

    for (int i = 0; i < Geny.size(); i++)
    {
        tem = 0;
        if (Geny[i].size() == GenyR[i].size())
        {
            for (int j = 0; j < Geny[i].size(); j++)
            {
                if (Geny[i][j] == GenyR[i][j])
                {
                    tem++;
                }
            }
            if (tem == Geny[i].size())
            {
                ileOpornych++;
            }
        }
    }

    cout << "Genow opornych jest : " << ileOpornych << endl;
}

int main()
{
    Wczytywanie();

    Zadanie1();
    TworzenieGenow();
    Zadanie2();
    Zadanie3();
    Zadanie4();
}