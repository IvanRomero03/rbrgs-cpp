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

    int maxX,maxY,minX,minY;
    unordered_map<int,vi> xcoor;
    unordered_map<int,vi> ycoor;

    int n,x,y;
    cin >> n;

    cin >> x >> y;
    minX = x;
    maxX = x;
    minY = y;
    maxY = y;
    xcoor[x].pb(0);
    ycoor[y].pb(0);

    for (int i = 2; i < n; i++) {
        cin >> x >> y;
        minX = min(minX,x);
        minY = min(minY,y);
        maxX = max(maxX,y);
        maxY = max(maxY,y);

        xcoor[x].pb(i);
        ycoor[y].pb(i);

    }

    set<int> ans;

    for (int i : xcoor[minX]) 
        ans.insert(i);

    for (int i : xcoor[maxX]) 
        ans.insert(i);

    for (int i : xcoor[minY]) 
        ans.insert(i);

    for (int i : xcoor[maxY]) 
        ans.insert(i);
    
    for(auto i : ans) {
        cout << i << " ";
    }

    return 0;
}