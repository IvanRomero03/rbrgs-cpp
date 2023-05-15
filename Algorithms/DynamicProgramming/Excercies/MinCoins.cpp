// Rbrgs.cpp
//  Problem from https://cses.fi/problemset/task/1634
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
#define aFOR(i, arr) for (auto &i : arr)
#define pb push_back
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int DP(int n, vi &dp, vi &coins)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int mini = INT_MAX;
    int r;
    aFOR(i, coins)
    {
        if (n - i >= 0)
        {
            r = DP(n - i, dp, coins);
            if (r > 0)
            {
                mini = min(mini, r);
            }
        }
    }
    if (mini == INT_MAX)
    {
        dp[n] = 0;
        return -1;
    }
    mini++;
    dp[n] = mini;
    return mini;
}

int main()
{
    sync;
    int n, x;
    cin >> n >> x;
    vi coins(n);
    vi dp(x + 1, -1);
    dp[0] = 1;
    FOR(i, 0, n)
    {
        cin >> coins[i];
    }
    int res = DP(x, dp, coins);

    // aFOR(i, dp)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    if (res == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << res - 1 << endl;

    return 0;
}