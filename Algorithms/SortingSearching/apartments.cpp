#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define all(x) begin(x), end(x)
int n, m, k, ans;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    vector<int>a(n), b(m);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    sort(all(a));
    sort(all(b));
    for(int i=0, j=0; i<n&&j<m;){
        if( abs(a[i]-b[j])<=k ) ans++, i++, j++;
        else if( a[i]+k<b[j] ) i++;
        else j++;
    }
    cout<<ans;
}
