class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        
        for(int ind = 1; ind < n; ind++) {
            int notPick = dp[ind - 1];
            int pick = nums[ind];
            if(ind - 2 >= 0 ) {
                pick += dp[ind - 2];
            }

            dp[ind] = max(pick, notPick);
        }
        
        
        return dp[n-1];
    }
};