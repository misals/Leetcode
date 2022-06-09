class Solution {
public:
    void generateAll(int n, int open, int close, vector<string> &ans, string str) {
        if(open == n && close == n) {
            ans.push_back(str);
        }
        if(open < n) {
            generateAll(n, open + 1, close, ans, str + '(');
        }
        if(close < open) {
            generateAll(n, open, close + 1, ans, str + ')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        vector<string> ans;
        
        generateAll(n, open, close, ans, "");
        
        return ans;
    }
};