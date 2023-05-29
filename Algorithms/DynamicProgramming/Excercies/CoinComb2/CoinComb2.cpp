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

int Combs(int n, int x, vector<int> &coins, vector<vector<int>> &dp)
{
    if (dp[n][x] != -1)
    {
        return dp[n][x];
    }
    if (x == 0)
    {
        dp[n][x] = 1;
        return 1;
    }
    int suma = 0;
    int res;
    if (coins[n] <= x)
    {
        res = Combs(n, x - coins[n], coins, dp);
        suma = res;
    }
    if (n > 0)
    {
        res = Combs(n - 1, x, coins, dp);
        suma = (suma + res) % MOD;
    }
    dp[n][x] = suma;
    return suma;
}

int main()
{
    sync;
    auto start = chrono::high_resolution_clock::now();
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);

    FOR(i, 0, n)
    {
        cin >> coins[i];
    }

    // sort(coins.begin(), coins.end(), greater<>());
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));

    // aFor(i, dp)
    // {
    //     i[0] = 1;
    // }
    int res = Combs(n - 1, x, coins, dp);

    cout << res << endl;
    auto end = chrono::high_resolution_clock::now();
    double executionTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    executionTime *= 1e-6;
    cout << "Exec time: " << fixed << executionTime << setprecision(6);
    cout << " ms " << endl;
    return 0;
}