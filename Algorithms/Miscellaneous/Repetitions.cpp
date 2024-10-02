// Rbrgs.cpp
#include <bits/stdc++.h>

#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define aFor(i, a) for (auto &i : a)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ll> vll;

int main()
{
    sync;
    string dna;
    cin >> dna;
    int maxC = 0, c = 0;
    for (int i = 1; i < dna.size(); i++)
    {
        if (dna[i] == dna[i - 1])
        {
            c++;
        }
        else
        {
            c = 0;
        }
        maxC = max(c, maxC);
    }
    cout << maxC + 1 << endl;
    return 0;
}