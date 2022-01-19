class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            int curr = flowerbed[i];
            if (curr == 0) {
                int prev = i == 0 ? 0 : flowerbed[i - 1];
                int next = i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1];
                if (prev == 0 && next == 0) {
                    count++;
                    flowerbed[i] = 1;
                }
            }
        }
        return count >= n;
    }
};