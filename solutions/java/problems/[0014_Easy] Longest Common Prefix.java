class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        StringBuilder ans = new StringBuilder(strs[0]);
        int matching = strs[0].length() - 1;
        for (int i = 1; i < n; i++) {
            String word = strs[i];
            matching = Math.min(matching, word.length() - 1);
            for (int j = 0; j <= matching; j++) {
                if (word.charAt(j) != ans.charAt(j)) {
                    matching = j - 1;
                    break;
                }
            }
        }
        if (matching < 0) return "";
        return ans.substring(0, matching + 1);
    }
}
