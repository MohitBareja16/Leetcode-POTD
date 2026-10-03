#include <string>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // Approach 1: Two Counters (O(1) Space)
    int longestValidParentheses(string s) {
        // Fast I/O
        static const auto fast = []() {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            return 0;
        }();
        (void)fast;

        int open = 0, close = 0;
        int res = 0;
        int n = s.length();
        
        // Left to Right scan
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                open++;
            } else {
                close++;
            }
            
            if (open == close) {
                res = max(res, open + close);
            }
            else if (close > open) {
                open = close = 0;
            }
        }
        
        open = 0;
        close = 0;
        
        // Right to Left scan
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '(') {
                open++;
            } else {
                close++;
            }
            
            if (open == close) {
                res = max(res, open + close);
            }
            else if (open > close) {
                open = close = 0;
            }
        }
       return res;
    }

    // Approach 2: Stack (O(N) Space)
    int longestValidParentheses_stack(string s) {
        stack<int> st;
        st.push(-1);
        int res = 0;
        
        for(int i = 0; i < (int)s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                } else {
                    res = max(res, i - st.top());
                }
            }
        }
        return res;
    }
};
