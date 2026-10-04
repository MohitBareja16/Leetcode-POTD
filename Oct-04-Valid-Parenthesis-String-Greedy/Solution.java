import java.util.Stack;

class Solution {
    // Approach 1: Greedy (Min/Max Open) - Optimal O(1) Space
    public boolean checkValidString(String s) {
        int minOpen = 0, maxOpen = 0;
        
        for (char c : s.toCharArray()) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else {
                minOpen--; // '*' acts as ')'
                maxOpen++; // '*' acts as '('
            }
            
            if (maxOpen < 0) return false;
            
            minOpen = Math.max(minOpen, 0);
        }
        
        return minOpen == 0;
    }

    // Approach 2: Two Passes - O(1) Space
    public boolean checkValidString_twoPass(String s) {
        int n = s.length();
        int count = 0, free = 0;
        
        // Left-to-Right
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == '(') count++;
            else if (c == ')') count--;
            else free++;
            
            if (count + free < 0) return false;
        }
        
        count = 0; free = 0;
        
        // Right-to-Left
        for (int i = n - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == ')') count++;
            else if (c == '(') count--;
            else free++;
            
            if (count + free < 0) return false;
        }
        
        return true;
    }

    // Approach 3: Two Stacks - O(N) Space
    public boolean checkValidString_stack(String s) {
        Stack<Integer> openStack = new Stack<>();
        Stack<Integer> starStack = new Stack<>();
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                openStack.push(i);
            } else if (c == '*') {
                starStack.push(i);
            } else {
                if (!openStack.isEmpty()) {
                    openStack.pop();
                } else if (!starStack.isEmpty()) {
                    starStack.pop();
                } else {
                    return false;
                }
            }
        }
        
        while (!openStack.isEmpty() && !starStack.isEmpty()) {
            if (openStack.peek() > starStack.peek()) {
                return false;
            }
            openStack.pop();
            starStack.pop();
        }
        
        return openStack.isEmpty();
    }
}
