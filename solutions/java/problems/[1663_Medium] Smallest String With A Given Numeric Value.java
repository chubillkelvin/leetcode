class Solution {
    public String getSmallestString(int n, int k) {
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = 1;
            k--;
        }
        int idx = 0;
        while (k > 0) {
            nums[idx] += Math.min(k, 25);
            k -= Math.min(k, 25);
            idx++;
        }
        StringBuilder ans = new StringBuilder();
        for (int i = n - 1; i >= 0; i--) {
            ans.append((char) ('a' + nums[i] - 1));
        }
        return ans.toString();
    }
}
