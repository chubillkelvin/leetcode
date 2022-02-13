struct Node {
    unordered_map<char, Node *> children;
    bool isEndOfWord = false;
};

class Trie {
    Node *root;
    string longest = "";
public:
    Trie() {
        root = new Node();
    }

    void add(string word) {
        int n = word.size();
        string longest = "";
        bool shouldAddToLongest = true;
        auto curr = root;
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (!curr->children[c]) curr->children[c] = new Node();
            curr = curr->children[c];
            if (shouldAddToLongest) {
                if (curr->isEndOfWord || i == n - 1) {
                    longest += c;
                } else {
                    shouldAddToLongest = false;
                }
            }
        }
        curr->isEndOfWord = true;
        if (longest.size() > this->longest.size()) this->longest = longest;
    }

    string getLongest() {
        return longest;
    }
};

class Solution {
public:
    string longestWord(vector <string> &words) {
        auto trie = new Trie();
        sort(words.begin(), words.end());
        for (string word: words) trie->add(word);
        return trie->getLongest();
    }
};