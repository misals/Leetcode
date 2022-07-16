class Solution {
public:
    int mod = 1000000007;
    
    int numOfWays(int i, int j, int n, int m, int maxMove, vector<vector<vector<int>>> &dp) {
        if(i < 0 || j < 0 || i >= m || j >= n) {
            return 1;
        }
        if(maxMove <= 0) return 0;
        
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        
        long res = 0;
        res += numOfWays(i, j-1, n, m, maxMove - 1, dp);
        res += numOfWays(i-1, j, n, m, maxMove - 1, dp);
        res += numOfWays(i, j+1, n, m, maxMove - 1, dp);
        res += numOfWays(i+1, j, n, m, maxMove - 1, dp);
        
        return dp[i][j][maxMove] = res % mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n+1, vector<int> (maxMove+1, -1)));
        return numOfWays(startRow, startColumn, n, m, maxMove, dp) % mod;
        
    }
};