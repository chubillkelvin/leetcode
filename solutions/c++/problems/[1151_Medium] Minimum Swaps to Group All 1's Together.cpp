class Solution {
public:
    int minSwaps(vector<int> &data) {
        int n = data.size();
        int sum = 0;
        for (int num: data) sum += num;
        int zeroCount = 0;
        for (int i = 0; i <= sum - 1; i++) if (data[i] == 0) zeroCount++;
        int minCount = zeroCount;
        for (int left = 1, right = sum; right < n; left++, right++) {
            if (data[left - 1] == 0) zeroCount--;
            if (data[right] == 0) zeroCount++;
            minCount = min(zeroCount, minCount);
        }
        return minCount;
    }
};