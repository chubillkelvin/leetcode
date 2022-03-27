class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int n = mat.length;
        var nums = new int[n][2];
        for (int i = 0; i < n; i++) {
            var row = mat[i];
            int total = 0;
            for (int num : row) total += num;
            nums[i] = new int[]{total, i};
        }
        Arrays.sort(nums, (a, b) -> {
            if (a[0] == b[0]) return a[1] - b[1];
            return a[0] - b[0];
        });
        var ans = new int[k];
        for (int i = 0; i < k; i++) ans[i] = nums[i][1];
        return ans;
    }
}
