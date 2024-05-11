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
typedef pair<int, ii> iii;

vii moves = {{1,2}, {2,1}, {-1,2}, {1,-2}, {2,-1}, {-2,1}, {-2,-1}, {-1,-2}};

inline bool validMove(int x, int y, int n) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}


int minMoves(set<ii> &caballos, vvi &v) {
    priority_queue<iii> pq;
    for(auto &cab:caballos) {
        pq.push({v[cab.first][cab.second], {cab.first, cab.second}});
    }
    // for(int i = 0; i < v.size(); i++){
    //     for(int j = 0; j < v[0].size(); j++) {
    //         if(caballos.find({i, j}) != caballos.end()){ 
    //             pq.push({v[i][j], {i, j}});
    //         }
    //     }
    // }
    int top = pq.top().first;
    if(top == 0) {
        return 0;    
    }
    int mini = INT_MAX;
    cout << "asdasdasd" << endl;
    while(!pq.empty() && pq.top().first == top && top != 0) {
        cout << pq.top().first << " " << pq.top().second.first << " " << pq.top().second.first << endl;
        caballos.erase(pq.top().second);
        for(auto &m:moves) {
            if(validMove(m.first + pq.top().second.first, m.second + pq.top().second.second, v.size())) { 
                v[m.first + pq.top().second.first][m.second + pq.top().second.second]--;
            }
        }
        mini = min(mini, minMoves(caballos, v) + 1);
        caballos.insert({pq.top().second.first, pq.top().second.second});
        for(auto &m:moves) {
            if(validMove(m.first + pq.top().second.first, m.second + pq.top().second.second, v.size())) { 
                v[m.first + pq.top().second.first][m.second + pq.top().second.second]++;
            }
        }
        // v[m.first + pq.top().second.first][m.second + pq.top().second.second]++;
        pq.pop();
    }
    return mini;
}

int main()
{
    sync;
    int n, k, a,b;
    cin >> n >> k;
    set<ii> caballos;
    vvi v(n, vi(n, 0));
    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        a--;
        b--;
        caballos.insert({a, b});
        for (auto &m:moves) {
            if(validMove(m.first + a, m.second + b, n)) {
                v[m.first + a][m.second + b]++;
            }
        }
    }
    // for(int i = 0; i < n; i ++) {
    //     for(int j = 0; j < n; j++) {
    //         v[0]
    //     }
    // }
    cout << "ASD" << endl;
    cout << minMoves(caballos, v) << endl;
    return 0;
}