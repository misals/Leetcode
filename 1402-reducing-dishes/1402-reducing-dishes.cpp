class Solution {
public:
    int solve(int ind, int time, vector<int> &nums, vector<vector<int>> &dp) {
        if(ind >= nums.size()) return 0;
        
        if(dp[ind][time] != -1) return dp[ind][time];
        
        int notPick = solve(ind + 1, time, nums, dp);
        int pick = nums[ind] * time + solve(ind + 1, time + 1, nums, dp);
        
        return dp[ind][time] = max(pick, notPick);
    }
    
    int maxSatisfaction(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        
        return solve(0, 1, nums, dp);
    }
};