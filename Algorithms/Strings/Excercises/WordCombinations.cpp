// Rbrgs.cpp
//  Word Combinations problem from https://cses.fi/problemset/task/1731
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

class TrieNode
{
public:
    vector<TrieNode *> childrens;
    bool isEndOfWord;
    int sizeOfChilds;
    TrieNode()
    {
        childrens = vector<TrieNode *>(26, nullptr);
        isEndOfWord = false;
        sizeOfChilds = 0;
    }
    void insertWord(string s, int i = 0)
    {
        if (s.size() == i)
        {
            isEndOfWord = true;
            return;
        }
        if (childrens[s[i] - 'a'] == nullptr)
        {
            childrens[s[i] - 'a'] = new TrieNode();
            sizeOfChilds++;
        }
        childrens[s[i] - 'a']->insertWord(s, i + 1);
    }
};

int WaysToFormString(string &, int, TrieNode *, vi &);

int WaysFromValidTrie(string &s, int i, TrieNode *root, vi &dp, TrieNode *node)
{
    int sum = 0;
    if (node->isEndOfWord)
    {
        sum = (sum + WaysToFormString(s, i, root, dp)) % MOD;
    }
    if (i == s.size())
    {
        return sum;
    }
    if (node->childrens[s[i] - 'a'] != nullptr)
    {
        sum = (sum + WaysFromValidTrie(s, i + 1, root, dp, node->childrens[s[i] - 'a'])) % MOD;
    }
    return sum;
}

int WaysToFormString(string &s, int i, TrieNode *root, vi &dp)
{
    if (dp[i] != -1)
    {
        return dp[i];
    }
    // cout << "DP at " << i << " " << s[i] << endl;
    if (root->childrens[s[i] - 'a'] == nullptr)
    {
        // cout << "At " << s[i] << " (" << i << ") there are no suffixs next in the Trie" << endl;
        dp[i] = 0;
        return 0;
    }
    dp[i] = WaysFromValidTrie(s, i + 1, root, dp, root->childrens[s[i] - 'a']);
    return dp[i];
}

int main()
{
    sync;
    string s, a;
    cin >> s;
    int n;
    cin >> n;
    TrieNode *root = new TrieNode();
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        root->insertWord(a);
    }
    vi dp(s.size() + 1, -1);
    dp[s.size()] = 1;
    cout << WaysToFormString(s, 0, root, dp) << endl;
    // ll res = ways(0, root, s, dp);
    // cout << res % MOD << endl;
    return 0;
}