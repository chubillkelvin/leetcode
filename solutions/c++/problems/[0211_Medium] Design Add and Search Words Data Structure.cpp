class WordDictionary {
    unordered_set <string> added;
    unordered_map<int, unordered_map<string, bool>> checked;
    unordered_map<int, vector<string>> dict;
public:
    WordDictionary() {

    }

    void addWord(string word) {
        dict[word.size()].push_back(word);
        checked[word.size()].clear();
        added.insert(word);
    }

    bool search(string word) {
        if (added.count(word) > 0) return true;
        if (checked[word.size()].find(word) != checked[word.size()].end()) return checked[word.size()][word];
        for (string w: dict[word.size()]) if (matched(w, word)) return checked[word.size()][word] = true;
        return checked[word.size()][word] = false;
    }

    bool matched(string word, string pattern) {
        for (int i = 0; i < word.size(); i++) {
            if (pattern[i] == '.') continue;
            if (word[i] != pattern[i]) return false;
        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */