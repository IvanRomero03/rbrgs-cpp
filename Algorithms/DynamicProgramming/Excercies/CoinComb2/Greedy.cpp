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

ll Ways(int x, vi &coins, vector<ll> &dp)
{
    if (dp[x] != -1)
    {
        return dp[x];
    }
    ll sum = 0;
    aFor(i, coins)
    {
        if (i <= x)
        {
            sum = (sum + Ways(x - i, coins, dp) % MOD) % MOD;
        }
    }
    dp[x] = sum;
    return sum;
}

int main()
{
    sync;
    int n, x;
    cin >> n >> x;

    vi coins(n);
    aFor(i, coins)
    {
        cin >> i;
    }
    sort(coins.begin(), coins.end(), greater<>());
    vector<ll> dp(x + 1, -1);
    dp[0] = 1;

    cout << Ways(x, coins, dp) << endl;

    return 0;
}