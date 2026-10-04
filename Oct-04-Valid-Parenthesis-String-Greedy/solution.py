class Solution:
    # Approach 1: Greedy (Min/Max Open) - Optimal O(1) Space
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
            else: # '*'
                min_open -= 1 # '*' acts as ')'
                max_open += 1 # '*' acts as '('
            
            # If max_open is negative, we have more ')' than '(' + '*'
            if max_open < 0:
                return False
            
            # min_open can't be negative, a negative min_open means we treated a '*' as ')' 
            # but it was better off being empty string ''
            min_open = max(min_open, 0)
            
        return min_open == 0

    # Approach 2: Two Passes - Left to Right, then Right to Left - O(1) Space
    def checkValidString_twoPass(self, s: str) -> bool:
        count = 0
        free = 0
        
        # Left-to-Right Scan
        for char in s:
            if char == '(': count += 1
            elif char == ')': count -= 1
            else: free += 1
            
            if count + free < 0:
                return False
                
        count = free = 0
        
        # Right-to-Left Scan
        for char in reversed(s):
            if char == ')': count += 1
            elif char == '(': count -= 1
            else: free += 1
            
            if count + free < 0:
                return False
                
        return True

    # Approach 3: Two Stacks - O(N) Space
    def checkValidString_stack(self, s: str) -> bool:
        open_stack = []
        star_stack = []
        
        for i, char in enumerate(s):
            if char == '(':
                open_stack.append(i)
            elif char == '*':
                star_stack.append(i)
            else:
                if open_stack:
                    open_stack.pop()
                elif star_stack:
                    star_stack.pop()
                else:
                    return False
        
        # Match remaining open brackets with stars that come AFTER them
        while open_stack and star_stack:
            if open_stack[-1] > star_stack[-1]:
                return False
            open_stack.pop()
            star_stack.pop()
            
        return not open_stack
