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

int main()
{
    sync;
    ll b_start = 0, b_end = 0, b_cost = 0, start, end, cost, profit = 0, N, S;
    cin >> N >> S;

    for (ll i = 0; i < N; ++i)
    {
        cin >> start >> end >> cost;

        ll max_profit = ((end - start + 1) * S) - cost;
        if (max_profit <= 0)
            continue;

        if (start <= b_end)
        {
            ll rem_prof = ((b_end - start + 1) * S) - max((ll)0, (ll)(b_cost - ((start - b_start + 1) * S)));
            if (rem_prof > max_profit)
                continue;
            else if (rem_prof == max_profit)
            {
                if (b_end > end)
                {
                    b_start = start,
                    b_end = end, b_cost = cost;
                    continue;
                }
            }
            else
            {
                profit -= ((b_end - b_start + 1) * S) - b_cost;
                ll temp = ((start - b_start) * S) - b_cost;
                profit += (temp > 0) ? temp + max_profit : max_profit;
            }
        }
        else
        {
            profit += max_profit;
        }
        b_start = start,
        b_end = end, b_cost = cost;
    }

    cout << profit;

    return 0;
}