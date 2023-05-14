// Rbrgs.cpp
#include <bits/stdc++.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define EPS 1e-6
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
    sync;
    int n, q;
    cin >> n >> q;
    long int a[n + 1] = {0};
    long int in, in2;
    for (int i = 1; i <= n; i++)
    {
        cin >> in;
        a[i] = a[i - 1] + in;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> in >> in2;
        cout << a[in2] - a[in - 1] << endl;
    }

    return 0;
}