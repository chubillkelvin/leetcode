class Solution {
    unordered_map <string, vector<string>> processed;
    unordered_map <string, unordered_set<string>> processedMap;
public:
    void processString(string s) {
        if (processed.find(s) == processed.end()) {
            int n = s.size();
            for (int i = 0; i < n; i++) {
                string newString = s;
                newString[i] = '*';
                processed[s].push_back(newString);
                processedMap[newString].insert(s);
            }
        }
    }

    int ladderLength(string beginWord, string endWord, vector <string> &wordList) {
        unordered_set <string> words;
        for (auto word: wordList) {
            words.insert(word);
            processString(word);
        }
        processString(beginWord);
        if (words.count(endWord) == 0) return 0;

        queue <unordered_set<string>> bfs;
        bfs.push({beginWord});
        words.erase(beginWord);
        int currLength = 1;
        while (!bfs.empty()) {
            currLength++;
            auto curr = bfs.front();
            unordered_set <string> next;
            for (auto w: curr) {
                unordered_set <string> nextSet;
                auto processedList = processed[w];
                for (auto processedWord: processedList) {
                    for (auto nextWord: processedMap[processedWord]) {
                        if (nextWord == endWord) return currLength;
                        if (words.count(nextWord) > 0) {
                            nextSet.insert(nextWord);
                        }
                    }
                }
                for (auto word: nextSet) {
                    words.erase(word);
                    next.insert(word);
                }
            }
            bfs.pop();
            if (!next.empty()) bfs.push(next);
        }
        return 0;
    }
};