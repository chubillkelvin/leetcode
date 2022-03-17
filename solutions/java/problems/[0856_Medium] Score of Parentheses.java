class Solution {
    public int scoreOfParentheses(String s) {
        int total = 0;
        Stack<Integer> st = new Stack();
        for (char c : s.toCharArray()) {
            if (c == '(') {
                st.push(0);
            } else {
                int temp = 0;
                while (st.peek() != 0) {
                    temp += st.pop();
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
}
