class Solution:
    def longestValidParentheses(self, s: str) -> int:
        """
        Approach 1: Two Counters (Left-to-Right and Right-to-Left)
        Space Complexity: O(1)
        """
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

    def longestValidParentheses_stack(self, s: str) -> int:
        """
        Approach 2: Stack
        Space Complexity: O(N)
        """
        stack = [-1]
        res = 0
        
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    # If stack is empty, this is the new boundary of a valid substring
                    stack.append(i)
                else:
                    res = max(res, i - stack[-1])
                    
        return res
