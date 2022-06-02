class Solution {
public:
    void generateAll(string str, vector<string> &res, int n, int open, int close) {
        if(open == n && close == n) {
            res.push_back(str);
            return;
        } 
        if(open < n) {
            generateAll(str + "(", res, n, open + 1, close);
        }
        if(close < open) {
            generateAll(str + ")", res, n, open, close + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open = 0;
        int close = 0;
        generateAll("", res, n, open, close);
        return res;
    }
};