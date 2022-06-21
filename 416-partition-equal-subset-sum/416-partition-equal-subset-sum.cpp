class Solution {
public:
    bool fun(int ind, int tar, vector<int> &nums, vector<vector<int>> &dp) {
        if(tar == 0) {
            return true;
        }
        if(ind == 0) return nums[ind] == tar;
        
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        bool notPick = fun(ind - 1, tar, nums, dp);
        bool pick = false;
        if(tar >= nums[ind]) {
            pick = fun(ind - 1, tar - nums[ind], nums, dp);
        }
        return dp[ind][tar] = pick | notPick;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum % 2) return false;
        
        vector<vector<int>> dp(n, vector<int> (sum/2+1, -1));
        
        return fun(n - 1, sum / 2, nums, dp);
    }
};