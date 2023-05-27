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
 
#define MAXN 1000005
#define MOD 1000000007

int n,m;
vi graph[MAXN];
vi visited(MAXN, 0);
int num = 1;
 
string bfs(int u) {
    visited[u] = num;
    queue<int> q;
    q.push(u);
    num *= -1;
    
    while(!q.empty()) {
        int f = q.front();
        q.pop();

        for (int i = 0; i < (int)graph[f].size(); i++) {
            // if (visited[f] == visited[graph[f][i]]) 
            //     return "IMPOSSIBLE";

            if (visited[graph[f][i]] == 0) {
                visited[graph[f][i]] = num;
                q.push(graph[f][i]);
                
            } else if (visited[graph[f][i]] == visited[f])
                return "IMPOSSIBLE";
        }
        num *= -1;
    }

    return "";

}

int main() { _
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;

        for (int i = 0; i < m; i++) {
            graph[a].pb(b);
            graph[b].pb(a);
        }
    }
    string res;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            res = bfs(i);
            if (res == "IMPOSSIBLE") {
                cout << res;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int n = visited[i];
        cout << ((n >= 1) ? 1 : 2) << " ";
    }

    return 0;
}