class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0 ));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(word1[i] == word2[j]) {
                    dp[i+1][j+1] = 1 + dp[i][j];
                } else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        int maxi = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                maxi = max(maxi, dp[i][j]);
            }
        }
        return abs(n - maxi) + abs(m - maxi);
    }
};