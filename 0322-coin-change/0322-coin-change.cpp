class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<long long>> dp(n, vector<long long> (amount + 1, -1));
        
        for(int i = 0; i <= amount; i++) {
            if(i % coins[0] == 0) {
                dp[0][i] = i / coins[0];
            }
            else {
                dp[0][i] = 1e5;
            }
        }
        
        for(int ind = 1; ind < n; ind++) {
            for(int tar = 0; tar <= amount; tar++) {
                long long notPick = dp[ind - 1][tar];
                long long pick = 1e5;

                if(tar >= coins[ind]) {
                    pick = 1 + dp[ind][tar - coins[ind]];
                }

                dp[ind][tar] = min(pick, notPick);
            }
        }
        
        long long ans = dp[n - 1][amount];
        
        if(ans == 1e5) {
            return -1;
        }
        return ans;
    }
};