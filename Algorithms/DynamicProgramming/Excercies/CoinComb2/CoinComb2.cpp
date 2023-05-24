// Rbrgs.cpp
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

ll Combs(int n, int x, vector<ll> &coins, vector<vector<ll>> &dp)
{
    if (dp[n][x] != -1)
    {
        return dp[n][x];
    }
    ll suma = 0;
    ll res;
    if (coins[n] <= x)
    {
        res = Combs(n, x - coins[n], coins, dp) % MOD;
        suma = (suma + res) % MOD;
    }
    if (n > 0)
    {
        res = Combs(n - 1, x, coins, dp) % MOD;
        suma = (suma + res) % MOD;
    }
    dp[n][x] = suma;
    return suma;
}

int main()
{
    sync;
    ll n, x;
    cin >> n >> x;

    vector<ll> coins(n);

    FOR(i, 0, n)
    {
        cin >> coins[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(x + 1, -1));

    aFor(i, dp)
    {
        i[0] = 1;
    }
    ll res = Combs(n - 1, x, coins, dp);

    cout << res << endl;

    return 0;
}