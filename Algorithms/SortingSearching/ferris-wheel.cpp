#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

#define all(x) begin(x), end(x)
int n, x, ans, sum;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>x;
    vector<int>p(n);
    for(int i=0; i<n; i++) cin>>p[i];
    multiset<int>m(all(p));

    while( m.size() ){
        int tmp = *begin(m);
        m.erase(begin(m));
        auto pt = m.upper_bound(x-tmp);
        if(pt!=m.begin()) m.erase(--pt);
        ans++;
    }
    cout<<ans;
}
