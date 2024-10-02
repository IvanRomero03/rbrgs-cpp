// Rbrgs.cpp
#include <bits/stdc++.h>

#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define aFor(i, a) for (auto &i : a)
#define ffor(i, n) for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ll> vll;

//\binom n k = \frac {n!} {k!(n-k)!}

/*
(n) _  __n!____
(k) -  k!(n-k)!
*/
int C(int n, int k)
{
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

// vll factorial(MAXN, 1);
// // factorial[0] = 1;
// for (int i = 1; i <= MAXN; i++)
// {
//     factorial[i] = factorial[i - 1] * i % m;
// }

void precalcFactorial(vll &factorial, ll m)
{
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        factorial[i] = factorial[i - 1] * i % m;
    }
}

long long binomial_coefficient(int n, int k, ll m, vll &factorial)
{
    return (factorial[n] / (factorial[k] * factorial[n - k] % m)) % m;
}

// long long binomial_coefficient(int n, int k)
// {
//     return factorial[n] * inverse_factorial[k] % m * inverse_factorial[n - k] % m;
// }

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    sync;
    int n;
    cin >> n;
    cout << C(n, 2 * n - 2) << endl;
    return 0;
}