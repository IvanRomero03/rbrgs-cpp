#include<iostream>
#include<set>
using namespace std;

int x, n, tmp;
multiset<int> ans;
multiset<int> light;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>x>>n;
    light.insert(0), light.insert(x), ans.insert(x);
    for(int i=0; i<n; i++){
        cin>>tmp;
        light.insert(tmp);
        auto m = light.find(tmp);
        int a = *prev(m), b = *next(m);
        ans.erase(ans.find(b-a));
        ans.insert(b-tmp), ans.insert(tmp-a);
        cout<<*ans.rbegin()<<" ";
    }
}
