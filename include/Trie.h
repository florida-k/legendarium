#pragma once
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
    bool isEnd; // marks end of a word
    vector<string> words;
    TrieNode* children[26]; // a–z child pointers

    TrieNode();
};

class Trie {
    TrieNode* root;
    void collect(TrieNode* node, vector<string>& out); // DFS collect
    void freeNode(TrieNode* node); // frees all nodes
    char normalizeChar(char c); // converts char to lowercase a–z

public:
    Trie();
    ~Trie();
    void insert(const string& word);
    bool search(const string& word);
    vector<string> startsWith(const string& prefix);
};
