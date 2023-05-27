#include<iostream>
#include<set>
using namespace std;
set<int>a;
int n, x, ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x;
        a.insert(x);
    }
    cout<< a.size();
}
