#include<iostream>
#include<set>
using namespace std;

int n, a, b, pp, maxPp;
multiset< pair<int,char> >t;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        t.insert( pair<int,char>(a,'a') );
        t.insert( pair<int,char>(b,'b') );
    }
    for(auto x:t){
        if(x.second=='a') pp++;
        else pp--;
        maxPp = max(maxPp, pp);
    }
    cout<<maxPp;
}
