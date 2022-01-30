class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 1) return nums[0] >= k ? 1 : 0;
        int minLen = n + 1;
        vector<long> p(n, 0);
        p[0] = nums[0];
        if (p[0] >= k) return 1;
        deque<int> d;
        d.push_back(0);
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            if (curr >= k) return 1;
            p[i] = p[i - 1] + curr;
            if (p[i] >= k) minLen = min(minLen, i + 1);
            while (!d.empty() && p[i] - p[d.front()] >= k) {
                minLen = min(minLen, i - d.front());
                d.pop_front();
            }
            while (!d.empty() && p[i] <= p[d.back()]) {
                d.pop_back();
            }
            d.push_back(i);
        }
        return minLen > n ? -1 : minLen;
    }
};