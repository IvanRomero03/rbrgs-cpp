// Rbrgs.cpp
#include <bits/stdc++.h>

#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define aFor(i, a) for (auto &i : a)
#define ffor(i, n) for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ll> vll;

int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

ll modPow(ll base, ll exp, ll mod)
{
    if (exp == 0)
    {
        return 1;
    }
    ll t = modPow(base, exp / 2, mod);
    t *= t;
    t %= mod;
    if (exp & 1)
    {
        t *= base;
        t %= mod;
    }
    return t;
}

ll inverseMod(ll n)
{
    return modPow(n, MOD - 2, MOD);
}

int main()
{
    sync;
    int p = 85, q = 10;
    cout << p * modPow(q, MOD - 2, MOD) % MOD << endl;
    return 0;
}