// Rbrgs.cpp
// Problem from: https://cses.fi/problemset/task/1638
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

int paths(int i, int j, vector<vector<char>> &grid, vector<vi> &dp)
{
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ways = 0, a;
    for (auto dir : vector<ii>{{1, 0}, {0, 1}})
    {
        if (i + dir.first < grid.size() && j + dir.second < grid[0].size())
        {
            ways = (ways + paths(i + dir.first, j + dir.second, grid, dp)) % MOD;
        }
    }
    dp[i][j] = ways;
    return ways;
}

int main()
{
    sync;
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vi> dp(n, vi(n, -1));
    dp[n - 1][n - 1] = 1;
    string line;
    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = line[j];
            if (line[j] == '*')
            {
                dp[i][j] = 0;
            }
        }
    }

    cout << paths(0, 0, grid, dp) << endl;

    return 0;
}