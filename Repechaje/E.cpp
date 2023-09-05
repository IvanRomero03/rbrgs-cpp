//Rbrgs.cpp
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

unordered_map<ll, ll> dp;
ll compute(ll x)
{
    if (dp.find(x) != dp.end())
    {
        return dp[x];
    }
    ll red = x % 10;
    ll x1 = x - red;
    x1 /= 10;
    // cout << x << " " << x1 << endl;
    ll ans = red + compute(x1);
    dp[x] = ans;
    return ans;

    // while (x > 0)
    // {
    //     ans += (x % 10);
    //     x = (x - (x % 10)) / 10;
    // }
    // //cout << ans << endl;
    // return ans;
}

ll solve(vi &arr, ll k)
{
    priority_queue<ll> pq;

    for (auto i : arr)
    {
        pq.push(i);
    }

    while (k--)
    {
        pq.push(pq.top() - compute(pq.top()));

        pq.pop();
    }

    return compute(pq.top());
}

int main()
{
    sync;
    dp[0] = 0;
    ll n, m, a;
    cin >> n >> m;
    vi arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // vector<int> arr = {22, 15, 7, 1};
    // int n = 3;

    cout << solve(arr, m - 1) << endl;

    return 0;
}