class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int[] count = new int[limit + 1];
        for (int p : people) count[p]++;
        int boats = count[limit];
        for (int i = 1; i < limit; i++) {
            while (count[i] > 0) {
                boats++;
                count[i]--;
                if (i > limit / 2) continue;
                for (int j = limit - i; j >= i; j--) {
                    if (count[j] > 0) {
                        count[j]--;
                        break;
                    }
                }
            }
        }
        return boats;
    }
}
