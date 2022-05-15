#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string> &words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            auto word = words[i];
            string temp = word;
            std::sort(temp.begin(), temp.end());
            if (i == 0 || temp != words[i - 1]) {
                ans.push_back(word);
            }
            words[i] = temp;
        }
        return ans;
    }
};