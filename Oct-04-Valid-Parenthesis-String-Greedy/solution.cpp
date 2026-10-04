#include <string>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // Approach 1: Greedy (Min/Max Open) - Optimal O(1) Space
    bool checkValidString(string s) {
        // Fast I/O
        static const auto fast = []() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            return 0;
        }();
        (void)fast;

        int min_open = 0;
        int max_open = 0;
        
        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else {
                min_open--;
                max_open++;
            }
            
            if (max_open < 0) return false;
            
            min_open = max(min_open, 0);
        }
        
        return min_open == 0;
    }

    // Approach 2: Two Passes - O(1) Space
    bool checkValidString_twoPass(string s) {
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

    // Approach 3: Two Stacks - O(N) Space
    bool checkValidString_stack(string s) {
        stack<int> open_stack;
        stack<int> star_stack;
        
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '(') {
                open_stack.push(i);
            } else if (s[i] == '*') {
                star_stack.push(i);
            } else {
                if (!open_stack.empty()) {
                    open_stack.pop();
                } else if (!star_stack.empty()) {
                    star_stack.pop();
                } else {
                    return false;
                }
            }
        }
        
        while (!open_stack.empty() && !star_stack.empty()) {
            if (open_stack.top() > star_stack.top()) {
                return false;
            }
            open_stack.pop();
            star_stack.pop();
        }
        
        return open_stack.empty();
    }
};
