#include "Trie.h"
#include <cctype>

TrieNode::TrieNode() {
    isEnd = false;
    for (int i = 0; i < 26; i++)
        children[i] = nullptr;
}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const string& word) {
    TrieNode* curr = root;

    for (char c : word) {
        if (!isalpha(c)) continue;
        c = tolower(c);
        int idx = c - 'a';

        if (!curr->children[idx])
            curr->children[idx] = new TrieNode();

        curr = curr->children[idx];
    }

    curr->isEnd = true;
}

bool Trie::search(const string& word) {
    TrieNode* curr = root;

    for (char c : word) {
        if (!isalpha(c)) continue;
        c = tolower(c);
        int idx = c - 'a';

        if (!curr->children[idx])
            return false;

        curr = curr->children[idx];
    }

    return curr->isEnd;
}

void Trie::collect(TrieNode* node, const string& prefix, vector<string>& out) {
    if (!node) return;
    if (node->isEnd) out.push_back(prefix);

    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            char c = 'a' + i;
            collect(node->children[i], prefix + c, out);
        }
    }
}

vector<string> Trie::startsWith(const string& prefix) {
    TrieNode* curr = root;
    vector<string> out;

    for (char c : prefix) {
        if (!isalpha(c)) continue;
        c = tolower(c);
        int idx = c - 'a';

        if (!curr->children[idx])
            return out;

        curr = curr->children[idx];
    }

    collect(curr, prefix, out);
    return out;
}
