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

int BookCombs(int x, vector<ii> &books, vi &dp)
{
    if (dp[x] != -1)
    {
        return dp[x];
    }
    int max_pages = 0;
    int cost = books.back().first;
    int pages = books.back().second;
    books.pop_back();

    if (x - cost >= 0)
    {
        max_pages = max(max_pages, BookCombs(x - cost, books, dp) + pages);
    }
    if (books.size() > 0)
    {
        max_pages = max(max_pages, BookCombs(x, books, dp));
    }
    books.push_back({cost, pages});

    dp[x] = max_pages;
    return max_pages;
}

int main()
{
    sync;
    int n, x;
    cin >> n >> x;
    vector<ii> books(n);
    aFor(i, books)
    {
        cin >> i.first;
    }
    aFor(i, books)
    {
        cin >> i.second;
    }

    vi dp(x + 1, -1);
    dp[0] = 0;

    cout << BookCombs(x, books, dp) << endl;

    return 0;
}