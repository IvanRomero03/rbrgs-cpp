#include<iostream>
#include<map>
using namespace std;

int n, x, tmp;
map<int, int> a;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>x;
    for(int i=1; i<=n; i++){
        cin>>tmp;
        if( a.count(x-tmp) ){
            cout<<a[x-tmp]<<" "<<i;
            return 0;
        }
        a[tmp] = i;
    }
    cout<<"IMPOSSIBLE";
}
