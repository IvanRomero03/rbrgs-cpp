#include<iostream>
using namespace std;

#define N 1005
#define X 100005
int n;
int h[N], s[N];
int dp[X];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x;
    cin>>n>>x;
    for(int i=1; i<=n; i++) cin>>h[i];
    for(int i=1; i<=n; i++) cin>>s[i];

    for(int i=1; i<=n; i++){
        for(int j=x; j>=h[i]; j--){
            dp[j] = max(dp[j], dp[j-h[i]]+s[i] );
        }
    }
    cout<<dp[x];
}
