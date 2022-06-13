class Solution {
public:   
    int uniquePath(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }
        if(i == m - 1 && j == n - 1) {
            return 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int bottom = uniquePath(i+1, j, m, n, dp);
        int right = uniquePath(i, j+1, m, n, dp);
        
        return dp[i][j] = bottom + right;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return uniquePath(0, 0, m, n, dp);
    }
};