class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), curr(amount+1, 0);
        for(int i = 0; i <= amount; i++) {
            if(i % coins[0] == 0)
                prev[i] = 1;
        }
        
        for(int ind = 1; ind < n; ind++) {
            for(int tar = 0; tar <= amount; tar++) {
                int notPick = prev[tar];
                int pick = 0;
                if(tar >= coins[ind]) {
                    pick = curr[tar - coins[ind]];
                }
                curr[tar] = pick + notPick;
            }
            prev = curr;
        }
        return prev[amount];
    }
};