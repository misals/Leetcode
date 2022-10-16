class Solution {
public:
    int solve(int ind, int d, int n, vector<int> &arr, vector<vector<int>> &dp) {
        if(d == 1) {
            return *max_element(arr.begin() + ind, arr.end());
        }
        if(dp[ind][d] != -1) return dp[ind][d];
        
        int res = INT_MAX;
        int currD = INT_MIN;
        
        for(int i = ind; i <= n - d; i++) {
            currD = max(currD, arr[i]);
            res = min(res, currD + solve(i + 1, d - 1, n, arr, dp));
        }
        
        return dp[ind][d] = res;
    }
    
    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size();
        
        if(d > n) return -1;
        
        vector<vector<int>> dp(n + 1, vector<int> (d + 1, -1));
        
        return solve(0, d, n, arr, dp);
    }
};