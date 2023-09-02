#include<iostream>
#include<set>
using namespace std;

int n, ans, tmp;
multiset<int>k;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tmp;
        auto it = k.upper_bound(tmp);
        if(it == k.end()) ans++;
        else k.erase(it);
        k.insert(tmp);
    }
    cout<<ans;
}
