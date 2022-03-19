class FreqStack {
    int total = 0;
    unordered_map<int, int> count;
    priority_queue <tuple<int, int, int>> st;
public:
    FreqStack() {

    }

    void push(int val) {
        count[val]++;
        st.push(make_tuple(count[val], total, val));
        total++;
    }

    int pop() {
        auto p = st.top();
        st.pop();
        int val = get<2>(p);
        count[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */