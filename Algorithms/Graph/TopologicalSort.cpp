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
 
#define MAXN 100000
#define MOD 1000000007
 
stack<int> topoSort;
vi graph[MAXN];
vi visited(MAXN,-1);

//To print elements in a DAG(directed acyclical graph) in order 
void dfs2(int u) {
    visited[u] = 1;

    for (int i = 0; i < graph[u].size(); i++) {
        if (visited[graph[u][i]] == -1) 
            dfs2(graph[u][i]);
    }
    topoSort.push(u);
}

int main() { _
    int n,m;
    cin >> n >> m;
  

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a].pb(b);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            dfs2(i);
            cout << i << endl;
        }
    }

    while (!topoSort.empty()) {
        cout << topoSort.top() << " ";
        topoSort.pop();
    }



    
return 0;


}