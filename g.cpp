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



int main()
{
    // O(nlogn)
    sync;
    int n, aasdasdasd;
    cin >> n;
    set<int> asd;
    for(int i = 0; i < n; i++) {
        cin >> aasdasdasd ;
        asd.insert(aasdasdasd);
    }
    vi v(asd.begin(), asd.end());
    // for(auto &i:v) {
    //     cout << i << " " << endl;
    // }

    // sort(v.begin(), v.end());
    n = v.size();
    bool aliciusWinning = true;
    if (v[0] == 1) {
        aliciusWinning = false;
        int cont = 1;
        while(cont < n && cont + 1 == v[cont]) {
            cont++;
            aliciusWinning = !aliciusWinning;
        }
        // aliciusWinning = (cont - 1) % 2;
        // cout << "a" << aliciusWinning << endl;
        // cout << cont << endl;
        if(cont == n) {
            aliciusWinning = !aliciusWinning;
        }
    }
    if (aliciusWinning) {
        cout << "Alicius" << endl;
    } else {
        cout << "Bobius" << endl;
    }
    return 0;
}