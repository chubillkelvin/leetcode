struct Node {
    vector<Node *> children = vector<Node *>(2, nullptr);
};

class Trie {
public:
    Node *root = new Node();

    Trie() {}

    int insert(string word, int maxSize) {
        auto curr = root;
        for (int i = 32 - maxSize; i < 32; i++) {
            int num = word[i] == '0' ? 0 : 1;
            if (!curr->children[num]) curr->children[num] = new Node();
            curr = curr->children[num];
        }
        return maxXor(word, maxSize);
    }

    int maxXor(string word, int maxSize) {
        string ans = "";
        auto curr = root;
        for (int i = 32 - maxSize; i < 32; i++) {
            int num = word[i] == '0' ? 0 : 1;
            if (num == 0 && curr->children[1]) {
                ans += '1';
                curr = curr->children[1];
            } else if (num == 1 && curr->children[0]) {
                ans += '1';
                curr = curr->children[0];
            } else {
                ans += '0';
                curr = curr->children[num];
            }
        }
        return stoi(ans, nullptr, 2);
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        auto trie = new Trie();

        int maxNum = INT_MIN;
        for (int num: nums) maxNum = max(maxNum, num);
        if (maxNum == 0) return 0;
        int maxSize = log10(maxNum) / log10(2) + 1;
        int maxSoFar = 0;
        for (int num: nums) {
            maxSoFar = max(maxSoFar, trie->insert(bitset<32>(num).to_string(), maxSize));
        }
        return maxSoFar;
    }
};