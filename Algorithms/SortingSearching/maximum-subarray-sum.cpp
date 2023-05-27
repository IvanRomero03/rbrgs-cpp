#include<iostream>
using namespace std;

#define INF 100000000000000000
long long n, sum, maxSum = -INF, tmp;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tmp;
        sum+= tmp;
        maxSum = max(maxSum, sum);
        if(sum<0) sum = 0;
    }
    cout<<maxSum;
}
