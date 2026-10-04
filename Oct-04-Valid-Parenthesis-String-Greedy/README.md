# Valid Parenthesis String - 3 Approaches (Greedy, Two-Pass, Stack)

**Problem Link:** [LeetCode - Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/)  
**Difficulty:** Medium  
**Date:** Oct 04, 2026  
**Topics:** `String`, `Greedy`, `Stack`, `Two Pointers`

---

## 💡 Intuition & Thought Process

This problem extends the classic "valid parentheses" challenge by introducing a wildcard `*` which can act as `(`, `)`, or empty string `""`. We can solve this with three distinct paradigms:

### Approach 1: Greedy (Min/Max Open) - **Most Optimal**
Instead of maintaining exact counts or tracking indices, we can track the **range** of possible open brackets at any given point:
- `min_open`: The minimum possible open left brackets (if we aggressively treat `*` as `)`).
- `max_open`: The maximum possible open left brackets (if we greedily treat `*` as `(`).
If `max_open` ever dips below `0`, it means even if we converted all `*` to `(`, we still have too many `)`. Thus, we return `false` early.
If `min_open` goes below `0`, we just cap it at `0` (meaning we treat some `*` as `""` instead of `)`).
At the very end, if `min_open == 0`, a valid string is possible!

### Approach 2: Two-Pass Scan
A brilliantly simple logic similar to tracking basic parentheses:
- **Left-to-Right**: Ensure that at no point do we have more `)` than `(` + `*`. This guarantees valid closing brackets.
- **Right-to-Left**: Ensure that at no point do we have more `(` than `)` + `*`. This handles cases where an open bracket is left unmatched at the end, like `"(*" ` or `"*( "`.

### Approach 3: Two Stacks
We maintain two stacks storing the **indices** of `(` and `*`.
- When encountering `)`, we pop from the `(` stack first. If empty, we pop from the `*` stack. If both are empty, it's invalid.
- After processing the string, we pair any remaining `(` with `*`. A valid pairing is only possible if the `(` comes **before** the `*` (i.e., `open_index < star_index`).

---

## 📊 Visual Walkthrough

### Greedy Min/Max approach for `s = "(*))"`

```text
Char   Action               min_open   max_open   Condition Check
-------------------------------------------------------------------
 (     +1 to both              1          1       max >= 0 ✅
 *     min - 1, max + 1        0          2       max >= 0 ✅
 )     -1 to both             -1->0       1       max >= 0 ✅ (min capped at 0)
 )     -1 to both             -1->0       0       max >= 0 ✅ (min capped at 0)
 
End of string: min_open == 0? YES ✅ (Valid string)
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$ for all 3 approaches. We either traverse the string once (Greedy, Stacks) or twice (Two-Pass).
- **Space Complexity:** 
  - **Greedy & Two-Pass:** $\mathcal{O}(1)$ as we only maintain a few integer counters.
  - **Stacks:** $\mathcal{O}(N)$ worst-case auxiliary space to store indices.

---

## 💻 Code Implementations

### Approach 1: Greedy Min/Max (Optimal $\mathcal{O}(1)$ Space)

# Code

```c++ []
class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0;
        int max_open = 0;
        
        for (char c : s) {
            if (c == '(') {
                min_open++; max_open++;
            } else if (c == ')') {
                min_open--; max_open--;
            } else {
                min_open--; max_open++;
            }
            
            if (max_open < 0) return false;
            min_open = max(min_open, 0);
        }
        
        return min_open == 0;
    }
};
```
```java []
class Solution {
    public boolean checkValidString(String s) {
        int minOpen = 0, maxOpen = 0;
        
        for (char c : s.toCharArray()) {
            if (c == '(') {
                minOpen++; maxOpen++;
            } else if (c == ')') {
                minOpen--; maxOpen--;
            } else {
                minOpen--; maxOpen++;
            }
            
            if (maxOpen < 0) return false;
            minOpen = Math.max(minOpen, 0);
        }
        
        return minOpen == 0;
    }
}
```
```python []
class Solution:
    def checkValidString(self, s: str) -> bool:
        min_open = 0
        max_open = 0
        
        for char in s:
            if char == '(':
                min_open += 1
                max_open += 1
            elif char == ')':
                min_open -= 1
                max_open -= 1
            else:
                min_open -= 1
                max_open += 1
            
            if max_open < 0:
                return False
            min_open = max(min_open, 0)
            
        return min_open == 0
```

### Approach 2: Two-Pass ($\mathcal{O}(1)$ Space)

# Code

```c++ []
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int count = 0, free = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') count++;
            else if (s[i] == ')') count--;
            else free++;
            if (count + free < 0) return false;
        }
        
        count = free = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') count++;
            else if (s[i] == '(') count--;
            else free++;
            if (count + free < 0) return false;
        }
        return true;
    }
};
```
```java []
class Solution {
    public boolean checkValidString(String s) {
        int n = s.length();
        int count = 0, free = 0;
        
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == '(') count++;
            else if (c == ')') count--;
            else free++;
            if (count + free < 0) return false;
        }
        
        count = 0; free = 0;
        for (int i = n - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == ')') count++;
            else if (c == '(') count--;
            else free++;
            if (count + free < 0) return false;
        }
        return true;
    }
}
```
```python []
class Solution:
    def checkValidString(self, s: str) -> bool:
        count = free = 0
        for char in s:
            if char == '(': count += 1
            elif char == ')': count -= 1
            else: free += 1
            
            if count + free < 0: return False
                
        count = free = 0
        for char in reversed(s):
            if char == ')': count += 1
            elif char == '(': count -= 1
            else: free += 1
            
            if count + free < 0: return False
                
        return True
```

### Approach 3: Two Stacks ($\mathcal{O}(N)$ Space)

# Code

```c++ []
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open_stack, star_stack;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') open_stack.push(i);
            else if (s[i] == '*') star_stack.push(i);
            else {
                if (!open_stack.empty()) open_stack.pop();
                else if (!star_stack.empty()) star_stack.pop();
                else return false;
            }
        }
        
        while (!open_stack.empty() && !star_stack.empty()) {
            if (open_stack.top() > star_stack.top()) return false;
            open_stack.pop();
            star_stack.pop();
        }
        
        return open_stack.empty();
    }
};
```
```java []
import java.util.Stack;
class Solution {
    public boolean checkValidString(String s) {
        Stack<Integer> openStack = new Stack<>();
        Stack<Integer> starStack = new Stack<>();
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') openStack.push(i);
            else if (c == '*') starStack.push(i);
            else {
                if (!openStack.isEmpty()) openStack.pop();
                else if (!starStack.isEmpty()) starStack.pop();
                else return false;
            }
        }
        
        while (!openStack.isEmpty() && !starStack.isEmpty()) {
            if (openStack.peek() > starStack.peek()) return false;
            openStack.pop();
            starStack.pop();
        }
        return openStack.isEmpty();
    }
}
```
```python []
class Solution:
    def checkValidString(self, s: str) -> bool:
        open_stack = []
        star_stack = []
        
        for i, char in enumerate(s):
            if char == '(': open_stack.append(i)
            elif char == '*': star_stack.append(i)
            else:
                if open_stack: open_stack.pop()
                elif star_stack: star_stack.pop()
                else: return False
        
        while open_stack and star_stack:
            if open_stack[-1] > star_stack[-1]: return False
            open_stack.pop()
            star_stack.pop()
            
        return not open_stack
```
