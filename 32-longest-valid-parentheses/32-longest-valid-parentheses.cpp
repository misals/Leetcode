class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int open = 0;
        int close = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                open++;
            } else {
                close++;
            }
            if(open == close) {
                maxLen = max(maxLen, 2 * open);
            }
            else if(close >= open) {
                open = 0;
                close = 0;
            }
        }
        
        open = 0;
        close = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '(') {
                open++;
            } else {
                close++;
            }
            if(open == close) {
                maxLen = max(maxLen, 2 * open);
            }
            else if(open >= close) {
                open = 0;
                close = 0;
            }
        }
        return maxLen;
    }
};