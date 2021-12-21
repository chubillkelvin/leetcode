#include <bits/stdc++.h>

using namespace std;

struct Pair {
    int num1, num2;
    int sum;

    Pair(int n1, int n2) {
        num1 = n1;
        num2 = n2;
        sum = n1 + n2;
    }

};

struct Comparator {
    bool operator()(Pair p1, Pair p2) {
        return p1.sum < p2.sum;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        priority_queue<Pair, vector<Pair>, Comparator> sum;
        for (int i = 0; i < min(n1, k); i++) {
            int num1 = nums1[i];
            for (int j = 0; j < min(n2, k); j++) {
                int num2 = nums2[j];
                sum.push(Pair(num1, num2));
                while (sum.size() > k) sum.pop();
            }
        }
        vector<vector<int>> ans;
        while (!sum.empty()) {
            auto p = sum.top();
            ans.push_back({p.num1, p.num2});
            sum.pop();
        }
        return ans;
    }
};