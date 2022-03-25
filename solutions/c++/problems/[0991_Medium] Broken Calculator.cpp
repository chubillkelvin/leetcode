class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        while (target != startValue) {
            if (target < startValue || target % 2 != 0) {
                target++;
            } else {
                target /= 2;
            }
            count++;
        }
        return count;
    }
};