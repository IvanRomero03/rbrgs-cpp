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
    int a, n;
    cin >> n;
    vi v(n - 1);
    unordered_set<int> us;
    aFor(i, v)
    {
        cin >> i;
        us.insert(i);
    }

    sort(v.begin(), v.end());
    int l = 0, r = v.size() - 1, mid;
    while (l < r)
    {
        mid = (r - l) / 2 + l;
        // cout << mid << " " << v[mid] << endl;
        if (mid + 1 != v[mid])
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (us.count(l + 1))
    {
        l++;
    }
    // cout << l << " " << r << endl;
    cout << l + 1 << endl;
    return 0;
}