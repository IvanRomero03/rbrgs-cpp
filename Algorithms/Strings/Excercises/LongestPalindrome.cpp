// Rbrgs.cpp
#include <bits/stdc++.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define EPS 1e-6
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define RFOR(i, a, b) for (int i = int(a) - 1; i >= int(b); i--)
#define FORC(it, cont) for (auto it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(it, cont) for (auto it = (cont).rbegin(); it != (cont).rend(); it++)
#define aFor(i, a) for (auto &i : a)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int LongestPalindrome(string &s, int l, int r, vvi &dp, int &maxLen, int &maxL, int &maxR)
{

    if (l >= r)
        return 1;
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    if (s[l] == s[r])
    {
        if (LongestPalindrome(s, l + 1, r - 1, dp, maxLen, maxL, maxR) == 1)
        {
            dp[l][r] = 1;
            if (maxLen < (r - l + 1))
            {
                maxLen = r - l + 1;
                maxL = l;
                maxR = r;
            }
            return dp[l][r];
        }
    }
    dp[l][r] = 0;
    LongestPalindrome(s, l, r - 1, dp, maxLen, maxL, maxR);
    LongestPalindrome(s, l + 1, r, dp, maxLen, maxL, maxR);
    return 0;
}

int main()
{
    sync;
    string s;
    cin >> s;
    cout << "aqui 1" << endl;
    int size = s.size();
    cout << "size " << size << endl;
    vector<vector<int>> dp;
    dp.assign(size, vector<int>(size, -1));
    int maxLen = 0;
    int l = 0;
    int r = 0;
    cout << "aqui " << endl;
    LongestPalindrome(s, 0, s.size() - 1, dp, maxLen, l, r);
    // cout << l << " " << r << endl;
    cout << "aqui " << l << " " << r << endl;
    cout << s.substr(l, r - l + 1) << endl;
    return 0;
}