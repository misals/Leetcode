class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));
        
        for(int ind = n - 1; ind >= 0; ind--) {
            for(int tran = 0; tran < 2*k; tran++) {
                if(tran % 2 == 0) {
                    dp[ind][tran] = max(-prices[ind] + dp[ind+1][tran+1],
                              0 + dp[ind+1][tran]);
                }
                else {
                    dp[ind][tran] = max(prices[ind] + dp[ind+1][tran+1],
                            0 + dp[ind+1][tran]);
                }
            }
        }
        
        return dp[0][0];
        
    }
};