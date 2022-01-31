class MedianFinder {
    priority_queue<int> minQ;
    priority_queue<int, vector<int>, greater<int>> maxQ;
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (minQ.empty() || num < minQ.top()) {
            minQ.push(num);
            while (minQ.size() - maxQ.size() > 1) {
                maxQ.push(minQ.top());
                minQ.pop();
            }
        } else {
            maxQ.push(num);
            while (maxQ.size() > minQ.size()) {
                minQ.push(maxQ.top());
                maxQ.pop();
            }
        }
    }

    double findMedian() {
        if ((minQ.size() + maxQ.size()) % 2 == 0) return (double) (minQ.top() + maxQ.top()) / 2;
        return minQ.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */