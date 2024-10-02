// Rbrgs.cpp
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int size_of_alphabet = 17;

int from_char_to_value(char c)
{
    if (c - '0' >= 0 && c - '0' <= 9)
    {
        return c - '0';
    }
    if (c - 'A' >= 0 && c - 'A' <= 5)
    {
        return 10 + c - 'A';
    }
}

class TrieNode
{
public:
    vector<TrieNode *> childs;
    int value;
    bool isEndOfWord;
    TrieNode *parent;
    TrieNode *failure;
    string endOfWord;
    TrieNode()
    {
        this->childs = vector<TrieNode *>(size_of_alphabet, nullptr);
        this->value = '$';
        this->isEndOfWord = false;
        this->parent = nullptr;
        this->endOfWord = "";
        this->failure = nullptr;
    }
    TrieNode(int value, TrieNode *parent = nullptr)
    {
        this->childs = vector<TrieNode *>(size_of_alphabet, nullptr);
        this->value = value;
        this->isEndOfWord = false;
        this->parent = parent;
        this->endOfWord = "";
        this->failure = nullptr;
    }
    ~TrieNode()
    {
        for (TrieNode *n : childs)
        {
            if (n != nullptr)
            {
                delete n;
            }
        }
    }
};

class AhoCorasick
{
private:
public:
    TrieNode root;
    AhoCorasick()
    {
        root = TrieNode();
        root.failure = &root;
    }
    int from_char_to_value(char c)
    {
        if (c - '0' >= 0 && c - '0' <= 9)
        {
            return c - '0';
        }
        if (c - 'A' >= 0 && c - 'A' <= 5)
        {
            return 10 + c - 'A';
        }
    }
    void AddWordToTrieHelper(string &s, int i, TrieNode *node)
    {
        if (i == s.size())
        {
            node->isEndOfWord = true;
            node->endOfWord = s;
            return;
        }
        int val = from_char_to_value(s[i]);
        if (node->childs[val] == nullptr)
        {
            node->childs[val] = new TrieNode(val, node);
        }
        AddWordToTrieHelper(s, i + 1, node->childs[val]);
    }
    void AddWordToTrie(string &s)
    {
        AddWordToTrieHelper(s, 0, &root);
    }
    void CalcFailureHelper(TrieNode *node)
    {
        node->failure = &this->root;
        if (node->parent->failure->childs[node->value] != nullptr)
        {
            node->failure = node->parent->failure->childs[node->value];
        }
        if (node->failure == node)
        {
            node->failure = &this->root;
        }
        for (auto n : node->childs)
        {
            if (n != nullptr)
            {
                CalcFailureHelper(n);
            }
        }
    }
    void CalcFailures()
    {
        for (auto n : root.childs)
        {
            if (n != nullptr)
            {
                CalcFailureHelper(n);
            }
        }
    }
    AhoCorasick(vector<string> &dict)
    {
        root = TrieNode();
        root.failure = &root;
        root.parent = &root;
        for (string &s : dict)
        {
            AddWordToTrie(s);
        }
        CalcFailures();
    }
    TrieNode *getTransition(TrieNode *node, int val)
    {
        if (node->childs[val] != nullptr)
        {
            return node->childs[val];
        }
        if (node->failure->childs[val] != nullptr)
        {
            return node->failure->childs[val];
        }
        return &root;
    }

    void helper(string &s, int i, unordered_map<string, vi> &res, queue<TrieNode *> &q)
    {
        if (i == s.size())
        {
            return;
        }
        int n = q.size();
        TrieNode *node;
        int value = from_char_to_value(s[i]);
        unordered_set<TrieNode *> visited;
        for (int j = 0; j < n; j++)
        {
            node = q.front();
            q.pop();
            TrieNode *transition = getTransition(node, value);
            if (visited.find(transition) == visited.end())
            {
                if (transition != &root)
                {
                    if (transition->isEndOfWord)
                    {
                        res[transition->endOfWord].push_back(i + 1 - transition->endOfWord.size());
                    }
                    q.push(transition);
                    visited.insert(transition);
                }
            }
        }
        if (root.childs[value] != nullptr && visited.find(root.childs[value]) == visited.end())
        {
            if (root.childs[value]->isEndOfWord)
            {
                res[root.childs[value]->endOfWord].push_back(i + 1 - root.childs[value]->endOfWord.size());
            }
            q.push(root.childs[value]);
        }
        helper(s, i + 1, res, q);
    }
    unordered_map<string, vi> findFindings(string &text)
    {
        unordered_map<string, vi> res;
        queue<TrieNode *> q;
        helper(text, 0, res, q);
        return res;
    }
};

int main()
{
    vector<string> dict = {"AF09", "AAB", "BBC0", "BBC", "AAA"};
    AhoCorasick aho(dict);
    string text = "AABBC0AF09BBC0AAA";
    cout << text << endl;
    unordered_map<string, vi> res = aho.findFindings(text);
    for (auto p : res)
    {
        cout << p.first << ": ";
        for (int i : p.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}