#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
public:
    map<char, TrieNode *> children = {};
    bool isEndOfWord = false;
};

class Trie {
public:
    struct TrieNode *root = new TrieNode();

    Trie() {

    }

    void insert(string word) {
        auto curr = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!curr->children[c]) {
                auto newNode = new TrieNode();
                curr->children[c] = newNode;
            }
            curr = curr->children[c];
            if (i == word.size() - 1) curr->isEndOfWord = true;
        }
    }

    bool search(string word) {
        auto curr = root;
        for (char c: word) {
            if (curr->children[c]) {
                curr = curr->children[c];
            } else {
                return false;
            }
        }
        return curr->isEndOfWord;
    }

    bool startsWith(string prefix) {
        auto curr = root;
        for (char c: prefix) {
            if (curr->children[c]) {
                curr = curr->children[c];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */