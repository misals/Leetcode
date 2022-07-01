class Solution {
public:
    int fun(int ind, int tran, int k, vector<int> &prices, int n, vector<vector<int>> &dp) {
        if(ind == n || tran == k) return 0;
        
        if(dp[ind][tran] != -1) return dp[ind][tran];
        
        if(tran % 2 == 0) {
            return dp[ind][tran] = max(-prices[ind] + fun(ind + 1, tran + 1, k, prices, n, dp),
                      0 + fun(ind + 1, tran, k, prices, n, dp));
        }
        
        return dp[ind][tran] = max(prices[ind] + fun(ind + 1, tran + 1, k, prices, n, dp),
                  0 + fun(ind + 1, tran , k, prices, n, dp));
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int> (2*k, -1));
        
        return fun(0, 0, 2*k, prices, n, dp);
        
    }
};