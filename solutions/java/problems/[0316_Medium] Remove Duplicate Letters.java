class Solution {
    public String removeDuplicateLetters(String s) {
        int n = s.length();
        int[] lastPos = new int[26];
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            lastPos[c - 'a'] = i;
        }
        Stack<Character> stack = new Stack<>();
        Set<Character> charSet = new HashSet<>();
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (!charSet.contains(c)) {
                while (!stack.empty() && stack.peek() > c && lastPos[stack.peek() - 'a'] > i) {
                    charSet.remove(stack.peek());
                    stack.pop();
                }
                charSet.add(c);
                stack.push(c);
            }
        }
        StringBuilder ans = new StringBuilder();
        for (Character c : stack) ans.append(c.charValue());
        return ans.toString();
    }
}
