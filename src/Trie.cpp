#include "Trie.h"
#include <cctype> // char validation and lowercase conversion

TrieNode::TrieNode() {
    isEnd = false;
    for (int i = 0; i < 26; i++)
        children[i] = nullptr;
}

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    freeNode(root);
}

void Trie::freeNode(TrieNode* node) {
    if (!node) return;
    for (int i = 0; i < 26; i++)
        if (node->children[i])
            freeNode(node->children[i]);
    delete node;
}

// converts alphabetic chars to lowercase; returns '\0' for non-letters
char Trie::normalizeChar(char c) {
    if (!isalpha((unsigned char)c)) return '\0';
    return (char)tolower((unsigned char)c);
}

void Trie::insert(const string& word) {
    TrieNode* curr = root;

    for (char c : word) {
        char nc = normalizeChar(c); // normalized
        if (nc == '\0') continue;   // skip non-letters
        int idx = nc - 'a';

        if (!curr->children[idx])
            curr->children[idx] = new TrieNode();

        curr = curr->children[idx];
    }

    curr->isEnd = true;
    curr->words.push_back(word); // store original name
}

bool Trie::search(const string& word) {
    TrieNode* curr = root;

    for (char c : word) {
        char nc = normalizeChar(c);
        if (nc == '\0') continue;
        int idx = nc - 'a';

        if (!curr->children[idx])
            return false;

        curr = curr->children[idx];
    }

    return curr->isEnd;
}

// DFS: collects stored words only (original names)
void Trie::collect(TrieNode* node, vector<string>& out) {
    if (!node) return;

    if (node->isEnd)
        for (const string& w : node->words)
            out.push_back(w);

    for (int i = 0; i < 26; i++)
        if (node->children[i])
            collect(node->children[i], out);
}

vector<string> Trie::startsWith(const string& prefix) {
    TrieNode* curr = root;
    vector<string> out;

    for (char c : prefix) {
        char nc = normalizeChar(c);
        if (nc == '\0') continue;
        int idx = nc - 'a';

        if (!curr->children[idx])
            return out;

        curr = curr->children[idx];
    }

    collect(curr, out);
    return out;
}