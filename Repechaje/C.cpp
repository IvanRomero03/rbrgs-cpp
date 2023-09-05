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

vi graph[MAXN];
vi visited(MAXN, -1);
vector<long> costs(MAXN, -1);

// void bfs()
// {
//     priority_queue<pair<ll, int> > pq;
//     pq.push({visited[1], 1});

//     while (!pq.empty())
//     {
//         pair<ll, int> front = pq.top();
//         pq.pop();
//         for (int i = 0; i < graph[front.second].size(); i++)
//         {
//             if (visited[graph[front.second][i]] == -1)
//             {
//                 visited[graph[front.second][i]] = (costs[graph[front.second][i]] > costs[front.second]) ? visited[front.second] + 1 : visited[front.second];
//                 pq.push({visited[graph[front.second][i]], graph[front.second][i]});
//             }
//         }
//     }
// }
// void dfs(int u)
// {

//     for (int i = 0; i < graph[u].size(); i++)
//     {
//         if (visited[graph[u][i]] == -1)
//         {
//             visited[graph[u][i]] = (costs[graph[u][i]] > costs[u]) ? visited[u] + 1 : visited[u];
//             dfs(graph[u][i]);
//         }
//     }
// }

// void dijkstra(int v, int s)
// {
//     vi dist(v, 0); // INF = 1B to avoid overflow
//     priority_queue<ii, vector<ii>, greater<ii>> pq;
//     pq.push(ii(0, s));

//     while (!pq.empty())
//     { // main loop
//         ii front = pq.top();
//         pq.pop(); // greedy: get shortest unvisited vertex
//         int d = front.first, u = front.second;

//         if (d > dist[u])
//             continue; // this is a very important check

//         for (int j = 0; j < (int)graph[u].size(); j++)
//         {
//             ii v = graph[u][j]; // all outgoing edges from u
//             if (dist[u] + v.second < dist[v.first])
//             {
//                 dist[v.first] = dist[u] + v.second; // relax operation
//                 pq.push(ii(dist[v.first], v.first));
//             }
//         }
//     }
//     // this variant can cause duplicate items in the priority queue
// }

int main()
{

    sync;
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        graph[i].pb(a);
        graph[a].pb(i);
    }

    for (int i = 1; i <= n; i++)
    {
        ll b;
        cin >> b;
        costs[i] = b;
    }

    priority_queue<pair<int, ii>> pq;
    pq.push({0, {0, 1}});
    vector<int> fotosEn(n + 1, 0);

    while (!pq.empty())
    {
        int node = pq.top().second.second;
        int currCost = pq.top().first;
        int fotos = pq.top().second.first;
        pq.pop();
        if (costs[node] > currCost)
        {
            fotos++;
            currCost = costs[node];
            fotosEn[node] = fotos;
        }
        for (int &i : graph[node])
        {
            if (fotosEn[i] < fotos)
            {
                pq.push({currCost, {fotos, i}});
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        cout << fotosEn[i] << " ";
    }

    return 0;
}