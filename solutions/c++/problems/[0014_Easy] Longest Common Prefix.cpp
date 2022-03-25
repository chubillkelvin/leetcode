struct TrieNode {
    unordered_map<char, TrieNode *> children;
};

class Trie {
    int minLen = INT_MAX;
    TrieNode *root = new TrieNode();
public:
    Trie() {}

    void add(string word) {
        minLen = min(minLen, (int) word.size());
        auto curr = root;
        for (char c: word) {
            if (!curr->children[c]) curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
    }

    string getLongestPrefix() {
        string ans = "";
        auto curr = root;
        while (curr->children.size() == 1 && ans.size() < minLen) {
            auto child = curr->children.begin();
            ans += child->first;
            curr = child->second;
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector <string> &strs) {
        auto trie = new Trie();
        for (auto word: strs) trie->add(word);
        return trie->getLongestPrefix();
    }
};