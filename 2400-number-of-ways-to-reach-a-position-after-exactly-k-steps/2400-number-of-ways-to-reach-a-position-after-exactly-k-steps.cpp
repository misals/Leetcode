class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int startPos, int endPos, int k, vector<vector<int>> &dp) {
        if(startPos == endPos && k == 0) {
            return 1;
        }
        if(k == 0) {
            return 0;
        }
        
        if(dp[startPos + 1000][k] != -1) {
            return dp[startPos + 1000][k];
        }
        
        long ans = solve(startPos + 1, endPos, k - 1, dp);
        if((k - 1) >= (endPos - startPos + 1)) {
            ans += solve(startPos - 1, endPos, k - 1, dp);
        }
        
        return dp[startPos + 1000][k] = ans % mod;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3001, vector<int> (1001, -1));
        
        return solve(startPos, endPos, k, dp) % mod;
    }
};