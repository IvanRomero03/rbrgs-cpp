#include<iostream>
#include<vector>
#include<set>
using namespace std;

#define all(x) begin(x), end(x)
int n, m;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    vector<int> h(n), t(m);
    for(int i=0; i<n; i++) cin>>h[i];
    for(int i=0; i<m; i++) cin>>t[i];
    multiset<int> hs(all(h));
    for(int i=0; i<m; i++){
        auto pt = hs.upper_bound(t[i]);
        if(pt==begin(hs)) cout<<"-1\n";
        else{
            cout<<*(--pt)<<"\n";
            hs.erase(pt);
        }
    }
}
