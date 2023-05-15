// Rbrgs.cpp
// Problem from https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define EPS 1e-6
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

ll ways(int n, vector<ll> &dp)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    ll sum = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (n - i >= 0)
        {
            ll to_sum = ways(n - i, dp) % MOD;
            sum += to_sum;
        }
    }
    dp[n] = sum % MOD;
    return sum % MOD;
}

int main()
{
    sync;
    int n;
    cin >> n;
    vector<ll> dp(n + 1, -1);
    dp[1] = 1;
    dp[0] = 1;
    cout << ways(n, dp) << endl;
    return 0;
}