//Rbrgs.cpp
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
typedef pair<ii, ii> iiii;

int getUpperBound(vi &v, int s, int f) {

}

ii getPals(int start, int fin, int k, string& s, vvi &v) {
    if(k == 0) {
        return {0, max(0, fin-start)};
    }
    if((start >= fin) || (start + 1 == fin)) {
        return {-1, -1};
    }
    priority_queue<iiii, vector<iiii>, greater<iiii>> qp;
    for(int i = start; i <= fin; i++) {
        if(v[s[i] - 'a'].size() > 1) {
            auto indx = lower_bound(v[s[i] - 'a'].begin(), v[s[i] - 'a'].end(), fin);
            if((*indx) > i && (*indx) <= fin) {
                ii val = getPals(i+1, (*indx) - 1, k - 2, s, v);
                if (val != ii({-1, -1})) {
                    qp.push({val, {i, (*indx)}});
                }
            }
        }
    }
    if(qp.empty()) {
        return {-1, -1};
    }
    
}

int main()
{
    sync;   
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vvi v(26);
    for(int i = 0; i < n; i++) {
        v[s[i] - 'a'].pb(i);
    }
    for(int i = 0; i < n; i++) {
        if(v[s[i] - 'a'].size() > 1) {
            // meterse al rango
            // maximo de palindromos hasta k - 2
            // maximo de chars que se pueden cambiar dentro del rango
        }
    }
    return 0;   
}