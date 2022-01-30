struct Node {
    unordered_map<char, Node*> children;
    bool isEndOfWord = false;
};

class WordDictionary {
    Node* root = new Node();
public:
    WordDictionary() {

    }

    void addWord(string word) {
        auto curr = root;
        for(char c: word) {
            if (!curr->children[c]) curr->children[c] = new Node();
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        auto curr = vector<Node*>{root};
        for (char c: word) {
            vector<Node*> next;
            for (auto node: curr) {
                if (c == '.') {
                    for (auto child: node->children) if (child.second) next.push_back(child.second);
                } else if (node && node->children[c]) {
                    next.push_back(node->children[c]);
                }
            }
            curr = next;
            if (curr.empty()) return false;
        }
        for (auto node: curr) if (node && node->isEndOfWord) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */