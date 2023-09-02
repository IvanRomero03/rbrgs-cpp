// Rbrgs.cpp
#include <bits/stdc++.h>

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

vector<int> z_function(string &s)
{
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

int main()
{
    sync;
    string s;
    cin >> s;
    vi z = z_function(s);
    for (int &i : z)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}