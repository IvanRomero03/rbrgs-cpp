//Rbrgs.cpp
#include <bits/stdc++.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define EPS 1e-6
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define RFOR(i, a, b) for (int i = int(a) - 1; i >= int(b); i--)
#define FORC(it, cont) for (auto it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(it, cont) for (auto it = (cont).rbegin(); it != (cont).rend(); it++)
#define aFor(i, a) for (auto &i : a)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
    sync;
    ll n, i;
    cin >> n;
    ll zeros = 0;
    ll cantUnos = 0, a;
    ll par = 0;
    ll impar = 0;
    ll res = 0;
    ll impares = 0, pares = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 0)
        {
            zeros++;
        }
        else
        {
            // cout << "uno at " << i << endl;
            cantUnos++;
            if (cantUnos % 2 == 0)
            {
                res += zeros * impares + impares + impar + zeros * impar;
                pares++;
                par += zeros;
                // zerosPares.pb({i, zerosPares.back().second + zeros + 1});
            }
            else
            {
                impares++;
                if (pares > 0)
                {
                    res += zeros * pares + pares + par + zeros * par;
                }
                impar += zeros;
                // zerosImpares.pb({i, zerosPares.back().second + zeros + 1});
            }
            zeros = 0;
        }
    }
    if (cantUnos % 2 == 0)
    {
        res += zeros * pares + pares + par + zeros * par;
    }
    else
    {
        res += zeros * impares + impares + impar + zeros * impar;
    }
    cout << res << endl;
    return 0;
}