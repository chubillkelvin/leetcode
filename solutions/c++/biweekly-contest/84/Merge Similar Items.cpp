#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2) {
        int n1 = items1.size();
        int n2 = items2.size();
        std::sort(items1.begin(), items1.end());
        std::sort(items2.begin(), items2.end());
        vector<vector<int>> ans;
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            auto check1 = items1[i];
            auto check2 = items2[j];
            if (check1[0] < check2[0]) {
                ans.push_back(check1);
                i++;
            } else if (check2[0] < check1[0]) {
                ans.push_back(check2);
                j++;
            } else {
                ans.push_back({check1[0], check1[1] + check2[1]});
                i++;
                j++;
            }
        }
        while (i < n1) {
            ans.push_back(items1[i++]);
        }
        while (j < n2) {
            ans.push_back(items2[j++]);
        }
        return ans;
    }
};