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
    ll n, a, b, c = 0;
    cin >> n;
    cin >> b;
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        if (a <= b)
        {
            c += b - a;
            a = b;
        }
        b = a;
    }
    cout << c << endl;
    return 0;
}