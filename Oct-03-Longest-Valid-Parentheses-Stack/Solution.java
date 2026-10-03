import java.util.Stack;

class Solution {
    // Approach 1: Two Counters (O(1) Space)
    public int longestValidParentheses(String s) {
        int open = 0, close = 0, res = 0;
        int n = s.length();
        
        // Left to Right scan
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                open++;
            } else {
                close++;
            }
            
            if (open == close) {
                res = Math.max(res, open + close);
            } else if (close > open) {
                open = close = 0;
            }
        }
        
        open = 0;
        close = 0;
        
        // Right to Left scan
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') {
                open++;
            } else {
                close++;
            }
            
            if (open == close) {
                res = Math.max(res, open + close);
            } else if (open > close) {
                open = close = 0;
            }
        }
        
        return res;
    }

    // Approach 2: Stack (O(N) Space)
    public int longestValidParentheses_stack(String s) {
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        int res = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.isEmpty()) {
                    stack.push(i); // New base index for valid substring
                } else {
                    res = Math.max(res, i - stack.peek());
                }
            }
        }
        return res;
    }
}
