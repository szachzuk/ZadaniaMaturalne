#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;
string linijki[1000];
int DlugosciT[1000];
void Wczytywanie()
{
    fstream plik;
    plik.open("dane_geny.txt");
    for (int i = 0; i < 1000; i++)
    {
        plik >> linijki[i];
    }
}
void Dlugosci()
{
    for (int i = 0; i < 1000; i++)
    {
        DlugosciT[i] = linijki[i].length();
    }
}
void zad1()
{
    multiset<int> DlugosciMS(DlugosciT, DlugosciT + 1000);
    set<int> DlugosciS(DlugosciMS.begin(), DlugosciMS.end());
    /*    for(auto e : DlugosciS)    {        cout<<e<<" "<<DlugosciMS.count(e)<<endl;    }    */ cout << DlugosciS.size() << endl;
    cout << "20" << endl;
}
pair<int, int> Gen(string s, int p)
{
    int poczatek = -1, koniec = -1;
    bool CzySzukamyPoczatek = true;
    for (int i = p; i < s.length() - 1; i++)
    {
        if (s[i] == 'A' and s[i + 1] == 'A' and CzySzukamyPoczatek)
        {
            poczatek = i;
            CzySzukamyPoczatek = false;
        }
        if (s[i] == 'B' and s[i + 1] == 'B' and CzySzukamyPoczatek == false)
            return {poczatek, i + 1};
    }
    return {poczatek, koniec};
}
bool Czy_mutacja(int p, int k, int i)
{
    string a = linijki[i].substr(p, k - p + 1);
    if (a.find("BCDDC") != -1)
        return true;
    return false;
}
// return a.find("BCDDC") != -1;}
bool CzyMutacjaZwierza(int i)
{
    pair<int, int> pk;
    pk = Gen(linijki[i], 0);
    while (true)
    {
        if (pk.second == -1)
            return false;
        if (Czy_mutacja(pk.first, pk.second, i))
            return true;
        pk = Gen(linijki[i], pk.second);
    }
}
int Ilosc_Genow(int i)
{
    int ile = 0;
    pair<int, int> pk;
    pk = Gen(linijki[i], 0);
    while (true)
    {
        if (pk.second != -1)
            ile++;
        else
            break;
        pk = Gen(linijki[i], pk.second);
    }
    return ile;
}
void Zad2()
{
    int ile = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (CzyMutacjaZwierza(i))
            ile++;
    }
    cout << endl
         << ile;
}

void Zad3()
{
    int m = 0;
    for (int i = 0; i < 1000; i++)
        if(Ilosc_Genow(i) > m)
            m = Ilosc_Genow(i);

    cout <<endl<< "Ilosc genow : " << m;
}

int main()
{
    Wczytywanie();
    Dlugosci();
    // zad1();
    //Zad2();
    Zad3();
    return 0;
}