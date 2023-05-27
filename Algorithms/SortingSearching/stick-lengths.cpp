#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define all(x) begin(x), end(x)
long long n, ans;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    vector<int>p(n);
    for(int i=0; i<n; i++) cin>>p[i];
    sort(all(p));
    for(int i=0; i<n; i++) ans += abs(p[i]-p[n/2]);
    cout<<ans;
}
