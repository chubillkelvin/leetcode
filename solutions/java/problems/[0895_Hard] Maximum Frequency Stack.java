class FreqStack {
    int maxCount;
    Map<Integer, Integer> count;
    Map<Integer, Stack<Integer>> stack;

    public FreqStack() {
        maxCount = 0;
        count = new HashMap<>();
        stack = new HashMap<>();
    }

    public void push(int val) {
        int freq = count.getOrDefault(val, 0) + 1;
        count.put(val, freq);
        if (freq > maxCount) {
            maxCount = freq;
            Stack<Integer> st = new Stack<>();
            st.push(val);
            stack.put(freq, st);
        } else {
            Stack<Integer> st = stack.get(freq);
            st.push(val);
            stack.put(freq, st);
        }
    }

    public int pop() {
        Stack<Integer> st = stack.get(maxCount);
        int val = st.pop();
        int freq = count.get(val) - 1;
        count.put(val, freq);
        if (st.empty()) {
            maxCount--;
        } else {
            stack.put(maxCount, st);
        }
        return val;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(val);
 * int param_2 = obj.pop();
 */
