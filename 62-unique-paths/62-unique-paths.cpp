class Solution {
public:
    int dp[101][101];
    int findAll(int i, int j, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return 0;
        }
        if(i == n - 1 && j == m - 1) {
            return 1;
        }
        if(dp[i][j] != 0) {
            return dp[i][j];
        }
        
        int bottom = findAll(i+1, j, n, m);
        int right = findAll(i, j+1, n, m);
        
        return dp[i][j] = bottom + right;
    }
    
    int uniquePaths(int m, int n) {
        return findAll(0, 0, n, m);
    }
};