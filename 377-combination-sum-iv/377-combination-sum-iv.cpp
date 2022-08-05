class Solution {
public:
    int solve(int ind, vector<int> &nums, int target, int n, vector<int> &dp) {
        if(ind == n) {
            if(target == 0) {
                return 1;
            }
            return 0;
        }
        if(dp[target] != -1) return dp[target];
        
        int notPick = solve(ind + 1, nums, target, n, dp);
        int pick = 0;
        if(target >= nums[ind]) {
            pick += solve(0, nums, target - nums[ind], n, dp);
        }
        return dp[target] = pick + notPick;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1, -1);
        return solve(0, nums, target, n, dp);
    }
};