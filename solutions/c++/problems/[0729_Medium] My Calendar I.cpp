class MyCalendar {
    set <pair<int, int>> nums;
public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        for (auto p: nums) {
            if (end <= p.first) {
                break;
            } else {
                if (start >= p.second) continue;
                return false;
            }
        }
        nums.insert(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */