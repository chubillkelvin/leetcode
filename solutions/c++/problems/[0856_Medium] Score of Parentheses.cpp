class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int total = 0;
        for (char c: s) {
            if (c == '(') {
                st.push(0);
            } else {
                int temp = 0;
                while (st.top() != 0) {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                if (temp > 0) {
                    temp *= 2;
                } else {
                    temp = 1;
                }
                if (st.empty()) {
                    total += temp;
                } else {
                    st.push(temp);
                }
            }
        }
        return total;
    }
};