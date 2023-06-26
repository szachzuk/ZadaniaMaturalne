#include <bits/stdc++.h>

using namespace std;

long long Liczby[1000];
vector<vector<long long>> Czynniki;
vector<long long> LiczbyPierwsze;

void Wczytywanie()
{
    ifstream plik("liczby.txt");
    for (long long i = 0; i < 1000; i++)
        plik >> Liczby[i];
}

void SitoErastotenesa()
{
    bool pierwsze[1000000000];
    fill(pierwsze, pierwsze + 1000000000, true);

    pierwsze[0] = false;
    pierwsze[1] = false;

    for (long long i = 4; i < 1000000000; i += 2)
        pierwsze[i] = false;

    for (long long i = 3; i <= 1000000000; i += 2)
        if (pierwsze[i])
            for (long long j = i + i; j < 1000000000; j += i)
                pierwsze[j] = false;

    for (long long i = 0; i < 1000000000; i++)
        if(pierwsze[i])
            LiczbyPierwsze.push_back(i);
}

bool CzyPierwsza(long long l)
{
    if (l == 2)
        return true;
    if (l == 1 or l % 2 == 0)
        return false;

    for (long long i = 3; i <= sqrt(l); i += 2)
        if (l % i == 0)
            return false;

    return true;
}

void RozkladNaCzynniki()
{
    vector<long long> C;

    for (long long i = 0; i < 1000; i++)
    {
        if (CzyPierwsza(Liczby[i]))
        {
            C.push_back(Liczby[i]);
            Czynniki.push_back(C);
        }
        else
        {
            long long l = Liczby[i];
            while (l > 2)
            {
                for (long long j = 2; j <= l; j++)
                {
                    if (l % j == 0 and CzyPierwsza(j))
                    {
                        C.push_back(j);
                        l /= j;
                        break;
                    }
                }
            }
        }
        Czynniki.push_back(C);
        C.clear();
    }
}

int main()
{
    Wczytywanie();
    SitoErastotenesa();
    //RozkladNaCzynniki();
    for (long long i = 0; i < 10; i++)
    {
        cout << LiczbyPierwsze[i] << endl;
    }


    return 0;
}