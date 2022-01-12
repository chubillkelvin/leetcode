class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int n = arr.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int currSize = 1;
            int currSum = arr[i];
            sum += currSum;
            for (int j = i + 1; j < n; j++) {
                currSize++;
                currSum += arr[j];
                if (currSize % 2 == 1) sum += currSum;
            }
        }
        return sum;
    }
};