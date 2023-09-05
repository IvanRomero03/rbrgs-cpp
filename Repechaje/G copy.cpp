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

    int maxX, maxY, minX, minY;

    int n, x, y;
    cin >> n;

    cin >> x >> y;
    minX = x;
    maxX = x;
    minY = y;
    maxY = y;
    vector<ii> cords = {{x, y}};
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        minX = min(minX, x);
        minY = min(minY, y);
        maxX = max(maxX, x);
        maxY = max(maxY, y);
        cords.push_back({x, y});
    }
    vi res;
    for (int i = 0; i <= n; i++)
    {
        if ((cords[i].first == minX || cords[i].first == maxX) || (cords[i].second == minY || cords[i].second == maxY))
        {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
    return 0;
}