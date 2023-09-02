// Rbrgs.cpp
#include <bits/stdc++.h>

using namespace std;

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

void TraverseTrie(TrieNode *node)
{
    if (node->isEndOfWord)
        cout << "end of word" << endl;
    for (int i = 0; i < 26; i++)
    {
        if (node->childrens[i] != nullptr)
        {
            cout << "traversing " << (char)(i + 'a') << endl;
            TraverseTrie(node->childrens[i]);
        }
    }
}

int main()
{
    TrieNode *root = new TrieNode();
    root->insertWord("hola");
    root->insertWord("hielo");
    root->insertWord("dado");
    root->insertWord("hielera");
    TraverseTrie(root);
    return 0;
}