#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1 = word1.size();
        int w2 = word2.size();

        if (w1 == 0) return w2;
        if (w2 == 0) return w1;

        vector<vector<int>> distance = vector<vector<int>>(w1 + 1, vector<int>(w2 + 1, 9999));

        // base case
        for (int i = 0; i <= w1; i++)
            distance[i][0] = i;
        for (int j = 0; j <= w2; j++)
            distance[0][j] = j;

        for (int i = 1; i <= w1; i++) {
            for (int j = 1; j <= w2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    distance[i][j] = distance[i - 1][j - 1];
                } else {
                    distance[i][j] = 1 + min(min(distance[i - 1][j], distance[i][j - 1]), distance[i - 1][j - 1]);
                }
            }
        }

        return distance[w1][w2];
    }
};
