#include<iostream>
using namespace std;

#define MOD 1000000007
#define N 1005
int n;
string grid;
int dp[N][N];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    dp[1][1] = 1;
    for(int i=1; i<=n; i++){
        cin>>grid;
        for(int j=1; j<=n; j++){
            if( i==1&&grid[j-1]=='*' ) dp[i][j] = 0;
            if( grid[j-1]=='.' ) dp[i][j] += (dp[i-1][j] + dp[i][j-1])%MOD;
        }
    }
    cout<<dp[n][n];
}
