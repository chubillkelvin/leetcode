#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getSpaces(int num) {
        string res = "";
        for (int i = 0; i < num; i++) {
            res += " ";
        }
        return res;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<vector<string>> linesOfWords = {{}};
        for (string word: words) {
            vector<string> *currLine = &linesOfWords[linesOfWords.size() - 1];
            int currLength = 0;
            for (string w: *currLine) {
                currLength += w.size();
            }
            currLength += currLine->size();
            if (currLength + word.size() <= maxWidth) {
                currLine->push_back(word);
            } else {
                linesOfWords.push_back({word});
            }
        }

        vector<string> ans = {};
        for (int index = 0; index < linesOfWords.size(); index++) {
            vector<string> line = linesOfWords[index];
            bool isLastLine = index == linesOfWords.size() - 1;
            int totalWordLength = 0;
            for (string word: line) {
                totalWordLength += word.size();
            }
            string mergedLine = "";
            int totalSpaces = maxWidth - totalWordLength;
            int gaps = line.size() - 1;
            string fullLine = "";
            if (isLastLine) {
                for (int j = 0; j < line.size(); j++) {
                    fullLine += line[j];
                    if (j != line.size() - 1) {
                        fullLine += " ";
                    } else {
                        fullLine += getSpaces(totalSpaces - j);
                    }
                }
            } else {
                for (int j = 0; j < line.size(); j++) {
                    fullLine += line[j];
                    if (j != line.size() - 1) {
                        int spaces = totalSpaces / gaps + (j < totalSpaces % gaps ? 1 : 0);
                        fullLine += getSpaces(spaces);
                    } else if (gaps == 0) {
                        fullLine += getSpaces(totalSpaces);
                    }
                }
            }
            ans.push_back(fullLine);
        }
        return ans;
    }
};