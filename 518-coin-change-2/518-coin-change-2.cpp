class Solution {
public:
    int coinChange(int ind, int tar, vector<int> &coins, vector<vector<int>> &dp) {
        if(ind == 0) {
            return (tar % coins[0] == 0);
        }
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        int notPick = coinChange(ind - 1, tar, coins, dp);
        int pick = 0;
        if(tar >= coins[ind]) {
            pick = coinChange(ind, tar - coins[ind], coins,dp);
        }
        return dp[ind][tar] = pick + notPick;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return coinChange(n-1, amount, coins, dp);
    }
};