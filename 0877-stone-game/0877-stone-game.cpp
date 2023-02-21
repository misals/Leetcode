class Solution {
public:
    int solve(int i, int j, vector<int> &nums, int turn, vector<vector<int>> &dp) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(turn == 0) {
            return dp[i][j] = max(nums[i] + solve(i + 1, j, nums, 1, dp),
                      nums[j] + solve(i, j - 1, nums, 1, dp));
        }
        
        return dp[i][j] = min(solve(i+1, j, nums, 0, dp),
                  solve(i,j-1, nums, 0, dp));
    }
    
    bool stoneGame(vector<int>& nums) {
        int alice = 0;
        int bob = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            bob += nums[i];
        }
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        alice = solve(0, n - 1, nums, 0, dp);
        
        bob -= alice;
        
        return alice >= bob;
    }
};