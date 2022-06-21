class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
        
        for(int i = 1; i <= amount; i++) {
            if(i % coins[0] == 0) prev[i] = i / coins[0];
            else prev[i] = 1e9;
        }
        
        for(int ind = 1; ind < n; ind++) {
            for(int tar = 1; tar <= amount; tar++) {
                int notPick = prev[tar];
                int pick = 1e9;
                if(tar >= coins[ind]) {
                    pick = 1 + curr[tar - coins[ind]];
                }
                curr[tar] = min(pick, notPick);
            }
            prev = curr;
        }
        if(prev[amount] >= 1e9) return -1;
        
        return prev[amount];
    }
};