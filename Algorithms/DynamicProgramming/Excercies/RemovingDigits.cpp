// Rbrgs.cpp
//  Problem from: https://cses.fi/problemset/task/1637
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

int Ways(int n, vi &dp)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int cp = n;
    int a;
    int mini = INT_MAX;
    while (cp > 0)
    {
        if (cp % 10 != 0)
        {
            a = Ways(n - (cp % 10), dp);
            if (a > 0)
            {
                mini = min(a, mini);
            }
            cp -= cp % 10;
            cp /= 10;
        }
        else
        {
            cp /= 10;
        }
    }
    if (mini == INT_MAX)
    {
        dp[n] = 0;
        return 0;
    }
    dp[n] = mini + 1;
    return mini + 1;
}

int main()
{
    sync;

    int n;
    cin >> n;

    vi dp(n + 1, -1);
    dp[0] = 1;
    cout << Ways(n, dp) - 1 << endl;

    return 0;
}