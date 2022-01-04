class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int num = n;
        int mask = 1;
        while (num > 0) {
            n ^= mask;
            mask <<= 1;
            num >>= 1;
        }
        return n;
    }
};