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

void solve(){
    ll t;
    cin >> t;
    unordered_map<ll, ll> umap;
    vi ord(t);
    ll max_ = 0;
    for(ll i = 0; i < t; i++){
        ll n; 
        cin >> n;
        n /= 2;
        ord[i] = n;
        umap[n] = -1;
        max_ = max(max_, n);
    }
    umap[0] = 1;

    vector<ll> states(10);
    states[0] = 1;

    for(ll i = 1; i <= max_; i++){
        vector<ll> next (10);
        next[1] = states[0];
        for(ll j = 2; j < 10; j++){
            next[j] = states[j-1];
            if (j & 1){
                (next[0] += next[j] * 3ll) %= MOD;
            } 
        }

        if (umap.count(i)){
            ll total = 0;
            for(auto x : next){
                (total += x) %= MOD;
            }
            umap[i] = total;
        }
        // cout << i << ": ";
        // for(auto x : next){
        //     cout << x << " ";
        // }
        // cout << "\n";

        states = next;
    }
    
    for(auto x : ord){
        cout << umap[x] << "\n";
    }


}

int main()
{
    sync;
    solve();
    return 0;
}