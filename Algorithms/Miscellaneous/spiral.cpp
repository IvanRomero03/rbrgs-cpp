// Rbrgs.cpp
#include <bits/stdc++.h>

#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define aFor(i, a) for (auto &i : a)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ll> vll;

int main()
{
    sync;
    int n, a, b;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        // 1 2 9 10 25 26 49
        //  1 7 1  15 1  23
        //
        if (a == 1 & b == 1)
        {
            cout << 1 << endl;
            continue;
        }
        ll maxi = max(a, b);
        ll res = (maxi - 1) * (maxi - 1);
        if (maxi % 2 == 0)
        {
            if (a >= b)
            {
                if()   
            }
        }
    }
    return 0;
}