#include<iostream>
#include<map>
using namespace std;

int n, tmp, ans, st;
map<int,int>vis;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>tmp;
        st = max(st, vis[tmp]);
        ans = max(ans, i-st);
        vis[tmp] = i;
    }
    cout<<ans;
}
