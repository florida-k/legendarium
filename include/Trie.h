#pragma once
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
    bool isEnd; // marks end of a word
    TrieNode* children[26]; // a–z child pointers

    TrieNode();
};

class Trie {
    TrieNode* root;
    void collect(TrieNode* node, const string& prefix, vector<string>& out);

public:
    Trie();
    void insert(const string& word);
    bool search(const string& word);
    vector<string> startsWith(const string& prefix);
};
