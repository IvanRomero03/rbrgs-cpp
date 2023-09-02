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

vector<int> preProcessPatern(string &s)
{
    vector<int> prefixTree(s.size(), 0);
    for (int i = 1; i < s.size(); i++)
    {
        if (s[prefixTree[i - 1]] == s[i])
        {
            prefixTree[i] = prefixTree[i - 1] + 1;
        }
        else
        {
            prefixTree[i] = (s[i] == s[0]) ? 1 : 0;
        }
    }
    return prefixTree;
}

int findMatch(string &text, string &pattern, vector<int> &prep)
{
    int i = 0, j = 0, n = text.size(), m = pattern.size(), count = 0;

    while ((n - i) >= (m - j))
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }

        if (j == m)
        {
            cout << "Found pattern at index " << i - j << endl;
            count++;
            j = prep[j - 1];
        }

        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
                j = prep[j - 1];
            else
                i = i + 1;
        }
    }

    return count;
}

int main()
{
    sync;
    string text = "aaabaaab", pattern = "aab";
    vi preprocess = preProcessPatern(pattern);
    for (int &i : preprocess)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << findMatch(text, pattern, preprocess) << endl;
    return 0;
}