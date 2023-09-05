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

    int d, c, r, ans =0;
    cin >> d >> c >> r;
    vi nums;

    while (c--) {
        int a;
        cin >> a;
        nums.pb(a);
    }

    while (r--) {
        int b;
        cin >> b;
        d+=b;
        ans++;
    }

    for (int i = 0; i < nums.size(); i++) {
        if(d-nums[i] >= 0) {
            d-=nums[i];
            ans++;
        } else
            break;

    }

    cout << ans;

    return 0;
}