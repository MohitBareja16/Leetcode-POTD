# Longest Valid Parentheses - Stack & Two Pointers

**Problem Link:** [LeetCode - Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)  
**Difficulty:** Hard  
**Date:** Oct 03, 2026  
**Topics:** `String`, `Dynamic Programming`, `Stack`

---

## 💡 Intuition & Thought Process

Finding the longest valid parentheses substring can be elegantly solved using either a **Stack** or **Two Counters**. 

### Approach 1: Two Counters (Optimized $\mathcal{O}(1)$ Space)
1. **Left-to-Right Scan**: As we iterate, we maintain `open` and `close` counts. If `open == close`, we have a valid substring of length `open + close`. If `close > open`, the string is strictly invalid up to this point, so we reset both counters to `0`.
2. **The Catch**: A purely left-to-right scan will fail to find the valid substring inside cases like `"(()"`, because `open` (2) will always be greater than `close` (1), and they never equalize to trigger a max calculation.
3. **Right-to-Left Scan**: To fix this, we do a second pass from right to left! This time, if `open > close`, it means there are too many open brackets, so we reset the counters. This guarantees we catch all valid inner blocks.

### Approach 2: Stack ($\mathcal{O}(N)$ Space)
Instead of counters, a stack keeps track of the **indices of unmatched parentheses**. 
1. We initialize the stack with `-1` (this represents an imaginary unmatched right parenthesis right before the string starts).
2. For `(`, we push its index to the stack.
3. For `)`, we pop the top of the stack.
   - If the stack becomes empty, it means this `)` is unmatched. We push its index as the new "base" for the next valid substring.
   - If the stack is not empty, the current valid substring length is `current_index - stack.top()`.

---

## 📊 Visual Walkthrough

### Two Counters Scan for `s = "(()"`

**1. Left-to-Right:**
```text
Char  Index   Open  Close   Action
---------------------------------------------
 (      0      1      0      Continue
 (      1      2      0      Continue
 )      2      2      1      open > close, no updates
# Max Length found = 0 (Misses the inner "()")
```

**2. Right-to-Left:**
```text
Char  Index   Open  Close   Action
---------------------------------------------
 )      2      0      1      Continue
 (      1      1      1      Match! (open == close) -> res = 2
 (      0      2      1      open > close -> Reset open=0, close=0
# Max Length found = 2
```

---

## ⏱️ Complexity Analysis

### Approach 1 (Two Counters)
- **Time Complexity:** $\mathcal{O}(N)$ since we make exactly two passes through the string.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space, making it the most optimal space solution.

### Approach 2 (Stack)
- **Time Complexity:** $\mathcal{O}(N)$ for a single pass through the string.
- **Space Complexity:** $\mathcal{O}(N)$ to store indices in the stack in the worst-case scenario (e.g. all left parentheses `(((((((...`).

---

## 💻 Code Implementations

Below are both the **Optimized Two Counters** and **Stack** approaches across Python, Java, and C++.

### Approach 1: Optimized Two Counters ($\mathcal{O}(1)$ Space)

# Code

```c++ []
class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, res = 0;
        int n = s.length();
        
        // Left to right scan
        for(int i = 0; i < n; i++){
            if(s[i] == '(') open++;
            else close++;
            
            if (open == close) {
                res = max(res, open + close);
            } else if (close > open) {
                open = close = 0;
            }
        }
        
        open = 0; close = 0;
        
        // Right to left scan
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '(') open++;
            else close++;
            
            if (open == close) {
                res = max(res, open + close);
            } else if (open > close) {
                open = close = 0;
            }
        }
       return res;
    }
};
```
```java []
class Solution {
    public int longestValidParentheses(String s) {
        int open = 0, close = 0, res = 0;
        int n = s.length();
        
        // Left to right scan
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') open++;
            else close++;
            
            if (open == close) res = Math.max(res, open + close);
            else if (close > open) open = close = 0;
        }
        
        open = 0; close = 0;
        
        // Right to left scan
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') open++;
            else close++;
            
            if (open == close) res = Math.max(res, open + close);
            else if (open > close) open = close = 0;
        }
        
        return res;
    }
}
```
```python []
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        open_count = 0
        close_count = 0
        res = 0
        
        # Left to Right scan
        for i in range(len(s)):
            if s[i] == '(':
                open_count += 1
            else:
                close_count += 1
            
            if open_count == close_count:
                res = max(res, open_count + close_count)
            elif close_count > open_count:
                open_count = close_count = 0
                
        open_count = 0
        close_count = 0
        
        # Right to Left scan
        for i in range(len(s) - 1, -1, -1):
            if s[i] == '(':
                open_count += 1
            else:
                close_count += 1
            
            if open_count == close_count:
                res = max(res, open_count + close_count)
            elif open_count > close_count:
                open_count = close_count = 0
                
        return res
```

### Approach 2: Stack ($\mathcal{O}(N)$ Space)

# Code

```c++ []
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int res = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if(st.empty()) {
                    // Push the index of the unmatched ')' as the new base
                    st.push(i);
                } else {
                    res = max(res, i - st.top());
                }
            }
        }
        return res;
    }
};
```
```java []
class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        int res = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.isEmpty()) {
                    stack.push(i);
                } else {
                    res = Math.max(res, i - stack.peek());
                }
            }
        }
        return res;
    }
}
```
```python []
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]
        res = 0
        
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    # Push the index of the unmatched ')' as the new base
                    stack.append(i)
                else:
                    res = max(res, i - stack[-1])
                    
        return res
```
