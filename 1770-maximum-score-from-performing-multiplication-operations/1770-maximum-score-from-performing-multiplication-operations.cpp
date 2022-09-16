class Solution {
public:
    int solve(int ind, int start, int end, vector<int> &nums, vector<int> &multipliers, vector<vector<int>> &dp) {
        if(ind == multipliers.size()) return 0;
        
        if(dp[ind][start] != INT_MIN) return dp[ind][start];
        int ans = INT_MIN;
        
        ans = max(multipliers[ind] * nums[start] + solve(ind + 1, start + 1, end, nums, multipliers, dp),
                  multipliers[ind] * nums[end] + solve(ind + 1, start, end - 1, nums, multipliers, dp));
        
        return dp[ind][start] = ans;
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();
        
        vector<vector<int>> dp(m, vector<int> (m, INT_MIN));
        
        return solve(0, 0, n - 1, nums, multipliers, dp);
    }
};