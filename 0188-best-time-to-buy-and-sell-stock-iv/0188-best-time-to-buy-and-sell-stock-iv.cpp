class Solution {
public:
    int solve(int ind, int buy, int k, vector<int> &prices, vector<vector<vector<int>>> &dp, int n) {
        if(ind >= n || k == 0) {
            return 0;
        }
        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];
        
        if(buy == 1) {
            return dp[ind][buy][k] = max(-prices[ind] + solve(ind + 1, 0, k, prices, dp, n),
                                      0 + solve(ind + 1, 1, k, prices, dp, n));
        }
        
        return dp[ind][buy][k] = max(prices[ind] + solve(ind + 1, 1, k - 1, prices, dp, n),
                                  0 + solve(ind + 1, 0, k, prices, dp, n));
                                      
                                      
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k+1, -1)));
        
        return solve(0, 1, k, prices, dp, n);
    }
};