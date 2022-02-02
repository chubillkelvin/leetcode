class MagicDictionary {
    unordered_map<int, vector<string>> dict;
public:
    MagicDictionary() {

    }

    void buildDict(vector <string> dictionary) {
        for (auto s: dictionary) dict[s.size()].push_back(s);
    }

    bool search(string searchWord) {
        int n = searchWord.size();
        auto dictSet = dict[n];
        if (dictSet.size() == 0) return false;
        for (auto word: dictSet) {
            int diff = 0;
            for (int i = 0; i < n; i++) {
                if (word[i] != searchWord[i]) diff++;
                if (diff > 1) break;
            }
            if (diff == 1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */