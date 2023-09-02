#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define all(x) begin(x), end(x)
int n, ans, tmp;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    vector< pair<int,int> >mv(n);
    for(int i=0; i<n; i++) cin>>mv[i].second>>mv[i].first;
    sort(all(mv));
    for(auto x:mv){
        if(x.second>=tmp) ans++, tmp=x.first;
    }
    cout<<ans;
}
