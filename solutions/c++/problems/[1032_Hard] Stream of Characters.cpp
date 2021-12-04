#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    map<char, TrieNode *> children = {};
    bool isEndOfWord = false;
};

class StreamChecker {
public:
    TrieNode *root = new TrieNode();
    vector<char> letters = {};

    StreamChecker(vector<string> &words) {
        for (string word: words) {
            auto curr = root;
            // put the word into the Trie in reverse order
            for (int i = word.size() - 1; i >= 0; i--) {
                char c = word[i];
                if (!curr->children[c]) curr->children[c] = new TrieNode();
                curr = curr->children[c];
                if (i == 0) curr->isEndOfWord = true;
            }
        }
    }

    bool query(char letter) {
        letters.push_back(letter);
        auto curr = root;
        for (int i = letters.size() - 1; i >= 0; i--) {
            char c = letters[i];
            if (curr->children[c]) {
                curr = curr->children[c];
            } else {
                return false;
            }
            if (curr->isEndOfWord) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */