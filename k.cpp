#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>
// #include <priority_queue>
 
#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000
 
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007

vii moves = {{1,2}, {2,1}, {-1,2}, {1,-2}, {2,-1}, {-2,1}, {-2,-1}, {-1,-2}};

inline bool validMove(int x, int y, int n) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int ans = INT_MAX;
void bt(int temp, vector<vi> crashes, int n, pair<int, ii> rem) {
    // cout << rem.first << " ";
    crashes[rem.second.first][rem.second.second] = 0;

    for (auto move : moves) {
        int x = rem.second.first + move.first;
        int y = rem.second.second + move.second;
        if (validMove(x,y,n) && crashes[x][y] > 0) {
            crashes[x][y]--;
        }
    }

    
    pair<int,ii> largest = {0,{0,0}};
    vector<vector<pair<int,ii>>> ops(n*n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (crashes[i][j] > largest.first) {
                largest = {crashes[i][j], {i,j}};
                ops[largest.first].pb(largest);
            }
        }
    }


    if (largest.first != 0) {
        for (auto x : ops[largest.first]){
            bt(temp + 1, crashes, n, x);
        }
    } else {
        ans = min(ans, temp);
        // cout << temp << " " << endl;
    }

    // cout << temp << " ";
}

int main() { _

    int n,k,a,b;
    cin >> n >> k;
    vii horses;

    vector<vi> positions(n, vi(n,0));


    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        horses.pb({a-1,b-1});
        positions[a-1][b-1] = 1;
    }

    vector<vi> crashes(n, vi(n, 0));

    for (auto horse: horses) {
        for (auto move : moves) {
            int x = horse.first + move.first;
            int y = horse.second + move.second;
            if (validMove(x,y,n) && positions[x][y]) {
                crashes[x][y]++;
            }
        }
    }

    // for (auto i : crashes) {
    //     for (auto j : i) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // bool crash = true;

    pair<int,ii> largest = {0,{0,0}};
    vector<vector<pair<int,ii>>> options(n*n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (crashes[i][j] >= largest.first) {
                largest = {crashes[i][j], {i,j}};
                options[largest.first].pb(largest);
            }
        }
    }

    // cout << options[largest.first].size();
    if (largest.first != 0) {

    for (auto x : options[largest.first]) {
        bt(1, crashes, n, x);
    }
    }

    if (ans == INT_MAX)
        ans = 0;

    cout << ans << endl;
    return 0;
}
    
