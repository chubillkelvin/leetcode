class Solution {
public:
    int minimumDeviation(vector<int> &nums) {
        priority_queue<int> maxHeap;
        int minimum = INT_MAX;
        for (int num: nums) {
            if (num % 2 == 1) num *= 2;
            maxHeap.push(num);
            minimum = min(minimum, num);
        }
        int diff = maxHeap.top() - minimum;
        while (maxHeap.top() % 2 == 0) {
            int curr = maxHeap.top();
            maxHeap.pop();
            curr /= 2;
            minimum = min(minimum, curr);
            maxHeap.push(curr);
            diff = min(diff, maxHeap.top() - minimum);
        }
        return diff;
    }
};