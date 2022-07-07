class Solution {
public:
    bool isInterleave(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp) {
        if(i == s1.size() && j == s2.size() && k == s3.size()) return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        
        bool x = false;
        bool y = false;
        if(i != s1.size()) {
            if(s1[i] == s3[k]) {
                x = isInterleave(s1, s2, s3, i+1, j, k+1, dp);
            }
        }
        if(j != s2.size()) {
            if(s2[j] == s3[k]) {
                y = isInterleave(s1, s2, s3, i, j+1, k+1, dp);
            }
        }
        return dp[i][j] = x || y;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        
        return isInterleave(s1, s2, s3, 0, 0, 0, dp);
    }
};