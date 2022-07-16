class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i = 0; i < m; i++) {
            dp[0][i] = matrix[0][i];
            ans += dp[0][i];
        }
        for(int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
            ans += dp[i][0];
        }
        if(matrix[0][0] == 1) ans--;
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};