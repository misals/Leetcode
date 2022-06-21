class Solution {
public:
    int f(int ind, int tar, vector<int> &coins, vector<vector<int>> &dp) {
        if(ind == 0) {
            if(tar % coins[0] == 0) return tar / coins[0];
            return 1e9;
        }
        if(dp[ind][tar] != -1) return dp[ind][tar];
        int notPick = f(ind - 1, tar, coins, dp);
        int pick = 1e9;
        if(tar >= coins[ind]) {
            pick = 1 + f(ind, tar - coins[ind], coins, dp);
        }
        
        return dp[ind][tar] = min(pick, notPick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = f(n-1, amount, coins, dp);
        
        if(ans >= 1e9) return -1;
        
        return ans;
    }
};