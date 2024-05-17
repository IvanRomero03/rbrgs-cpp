#include <bits/stdc++.h>
 
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

vector<int> m(vector<int> in){
    vector<int> ne;

    for(int i = 1; i < in.size(); i++){
        ne.push_back(in[i]);
    }

    ne.push_back(in[0]);
    return ne;
}

bool find(vector<int> look, int val){
    for(auto x : look){
        if (x == val)
            return true;
    }
    return false;

}

void dfs(int current, vector<int> &in, vector<int>& d2, vector<bool>& visited, int pos, int &ans){
    if (pos == 3){
        ans = max(ans, current);
        return;
    }

    for(int i = 0; i < 3; i++){
        if (!visited[i]){
            visited[i] = true;
            dfs(current * (in[pos] / d2[i]), in, d2, visited, pos+1, ans);
            visited[i] = false;
        }
    }
}

void solve2(){
     vector<int> d2;
    for(int i = 0; i < 3; i++){
        int n;
        cin >> n;
        d2.push_back(n);
    }
    vector<int> d;
    for(int i = 0; i < 3; i++){
        int n;
        cin >> n;
        d.push_back(n);
    }
    vector<bool> v(3);
    int ans = 0;
    dfs(1, d2, d, v, 0, ans);
    cout << ans << "\n";
}

void solve(){
    vector<int> d2;
    for(int i = 0; i < 3; i++){
        int n;
        cin >> n;
        d2.push_back(n);
    }
    vector<int> d;
    for(int i = 0; i < 3; i++){
        int n;
        cin >> n;
        d.push_back(n);
    }

    int ans = 0;

    for(int i = 0; i < 3; i++){
        d = m(d);
        for(auto x : d)
            cout << x << " ";
        cout << "\n";
        int min_ = INT_MAX;
        vector<int> coef;
        for(int j = 0; j < 3; j++){
            // min_ = min(min_, d2[j] / d[j]);
            coef.push_back(d2[j] / d[j]);
        } 
        cout << "coef: ";
        for(auto x :coef){
            cout << x << " ";
        }
        cout << "\n";
        int cur = 1;
        for(auto x : coef){
            cur *= x;
        }
        ans = max(ans, cur);
    }
    
    cout << ans << "\n";



}
int main()
{
    sync;
    solve2();
    return 0;
}