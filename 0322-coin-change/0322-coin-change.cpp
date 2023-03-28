class Solution {
public:
    int solve(int ind, int amount, vector<int> &coins, vector<vector<long long>> &dp) {
        if(ind == 0) {
            if(amount % coins[ind] == 0) {
                return amount / coins[ind];
            }
            return 1e5;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        
        long long notPick = solve(ind - 1, amount, coins, dp);
        long long pick = 1e5;
        
        if(amount >= coins[ind]) {
            pick = 1 + min(solve(ind, amount - coins[ind], coins, dp),
                          solve(ind - 1, amount - coins[ind], coins, dp));
        }
        
        return dp[ind][amount] = min(pick, notPick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<long long>> dp(n, vector<long long> (amount + 1, -1));
        
        long long ans = solve(n - 1, amount, coins, dp);
        
        if(ans == 1e5) {
            return -1;
        }
        return ans;
    }
};