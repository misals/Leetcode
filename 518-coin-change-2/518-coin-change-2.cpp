class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, 0));
        for(int i = 0; i <= amount; i++) {
            if(i % coins[0] == 0)
                dp[0][i] = 1;
        }
        
        for(int ind = 1; ind < n; ind++) {
            for(int tar = 0; tar <= amount; tar++) {
                int notPick = dp[ind - 1][tar];
                int pick = 0;
                if(tar >= coins[ind]) {
                    pick = dp[ind][tar - coins[ind]];
                }
                dp[ind][tar] = pick + notPick;
            }
        }
        return dp[n-1][amount];
    }
};