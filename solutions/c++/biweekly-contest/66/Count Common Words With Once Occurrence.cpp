#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countWords(vector<string> &words1, vector<string> &words2) {
        set<string> once = {};
        set<string> again = {};
        for (string word: words1) {
            if (once.count(word) == 0 && again.count(word) == 0) {
                once.insert(word);
            } else if (once.count(word) > 0) {
                once.erase(word);
                again.insert(word);
            }
        }

        set<string> match = {};
        for (string word: words2) {
            if (once.count(word) > 0 && match.count(word) == 0) {
                once.erase(word);
                match.insert(word);
            } else if (match.count(word) > 0) {
                match.erase(word);
            }
        }
        return match.size();
    }
};