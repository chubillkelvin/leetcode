class Solution {
    public int minDominoRotations(int[] tops, int[] bottoms) {
        int n = tops.length;
        int[] topCount = new int[6];
        int[] botCount = new int[6];
        int[] uniqueCount = new int[6];
        for (int i = 0; i < n; i++) {
            topCount[tops[i] - 1]++;
            botCount[bottoms[i] - 1]++;
            if (tops[i] == bottoms[i]) {
                uniqueCount[tops[i] - 1]++;
            } else {
                uniqueCount[tops[i] - 1]++;
                uniqueCount[bottoms[i] - 1]++;
            }
        }
        int ans = n + 1;
        for (int i = 0; i < 6; i++) {
            if (uniqueCount[i] != n) continue;
            ans = Math.min(ans, Math.min(n - topCount[i], n - botCount[i]));
        }
        return ans == n + 1 ? -1 : ans;
    }
}
