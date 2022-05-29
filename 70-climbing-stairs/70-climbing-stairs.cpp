class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        int ans = rec(n , dp);
        return ans;
    }
    
    int rec(int n, vector<int> &dp) {
        if(n <= 1) {
            return 1;
        }
        if(dp[n] > 0) {
            return dp[n];
        }
        int val1 = rec(n - 1, dp);
        int val2 = rec(n - 2, dp);
        dp[n] = val1 + val2;
        return val1 + val2;
    }
};