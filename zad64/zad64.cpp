#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> dane;
int ZliczanieCzarnych(int indeks)
{
    int il = 0;
    for (int j = 0; j < 20; j++)
        if (dane[indeks][j] == "1")
            il++;
    return il;
}
void Zadanie1()
{
    int il_cz, il_bi, ile_rewers = 0;
    for (int i = 0; i < 200; i++)
    {
        il_cz = ZliczanieCzarnych(i);
        il_bi = 400 - il_cz;
        if (il_cz > il_bi)
            ile_rewers++;
    }
    cout << "Zadanie 1" << endl;
    cout << ile_rewers << endl;
}
int main()
{
    ifstream plik("dane_obrazki.txt");
    string l;

    vector<string> obraz;
    while (!plik.eof())
    {
        for (int j = 0; j < 21; j++)
        {
            plik >> l;
            obraz.push_back(l);
        }
        dane.push_back(obraz);
        obraz.clear();
    }

    Zadanie1();
}