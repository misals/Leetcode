class Solution {
public:
    int fun(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0 && i >= 0) {
            for(int ind = 0; ind <= i; ind++) {
                if(s[ind] != '*')
                    return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || s[i] == '?') {
            return dp[i][j] = fun(i-1, j-1, s, p, dp);
        }
        if(s[i] == '*') {
            return dp[i][j] = fun(i-1, j, s, p, dp) | fun(i, j-1, s, p, dp);
        }
        return dp[i][j] = false;
    } 
    
    bool isMatch(string p, string s) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        
        return fun(n-1, m-1, s, p, dp);
    }
};