#pragma once
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* children[26];

    TrieNode();
};

class Trie {
private:
    TrieNode* root;
    void collect(TrieNode* node, const string& prefix, vector<string>& out);

public:
    Trie();
    void insert(const string& word);
    bool search(const string& word);
    vector<string> startsWith(const string& prefix);
};
