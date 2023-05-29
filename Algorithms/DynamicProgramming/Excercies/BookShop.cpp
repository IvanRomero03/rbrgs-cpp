// Rbrgs.cpp
// Problem from: https://cses.fi/problemset/task/1158
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

int MaxPages(int money, vector<ii> &books, vi &dp)
{
    cout << money << endl;
    if (dp[money] != -1)
    {
        return dp[money];
    }
    int max_pages = 0;
    for (auto &book : books)
    {
        if (book.first <= money)
        {
            max_pages = max(max_pages, MaxPages(money - book.first, books, dp) + book.second);
        }
    }
    dp[money] = max_pages;
    cout << max_pages << " for " << money << endl;
    return max_pages;
}

int main()
{
    sync;
    int n, money;
    cin >> n >> money;
    vector<ii> books(n);
    vi dp(money + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> books[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> books[i].second;
    }

    cout << MaxPages(money, books, dp) << endl;

    return 0;
}