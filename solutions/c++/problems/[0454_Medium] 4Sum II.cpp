class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n3 = nums3.size();
        int n4 = nums4.size();
        vector<int> sum1;
        for (int i = 0; i < n1; i++) {
            int num1 = nums1[i];
            for (int j = 0; j < n2; j++) {
                sum1.push_back(nums2[j] + num1);
            }
        }
        unordered_map<int, int> sum2;
        for (int i = 0; i < n3; i++) {
            int num3 = nums3[i];
            for (int j = 0; j < n4; j++) {
                sum2[nums4[j] + num3]++;
            }
        }
        int count = 0;
        for (int sum: sum1) {
            if (sum2[-sum] > 0) count += sum2[-sum];
        }
        return count;
    }
};