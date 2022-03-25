class Solution {
    public String encode(int num) {
        int power = 0;
        int prev = 0;
        int curr = 0;
        while (curr < num) {
            prev = curr;
            curr += Math.pow(2, ++power);
        }
        StringBuilder ans = new StringBuilder(Integer.toBinaryString(num - prev - 1));
        if (ans.length() > power) ans.setLength(power);
        while (ans.length() < power) ans.insert(0, '0');
        return ans.toString();
    }
}
