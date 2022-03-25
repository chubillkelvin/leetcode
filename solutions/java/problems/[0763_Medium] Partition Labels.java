class Solution {
    public List<Integer> partitionLabels(String s) {
        int n = s.length();
        int[] pos = new int[26];
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            pos[c - 'a'] = i;
        }
        List<Integer> list = new ArrayList<>();
        int start = 0;
        while (start < n) {
            char c = s.charAt(start);
            int end = pos[c - 'a'];
            for (int i = start + 1; i < end; i++) {
                char c2 = s.charAt(i);
                end = Math.max(end, pos[c2 - 'a']);
            }
            list.add(end - start + 1);
            start = end + 1;
        }
        return list;
    }
}
