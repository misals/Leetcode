class Solution {
public:
    int n;
    
    int solve(int ind, int k, vector<vector<int>> &piles, vector<vector<int>> &dp) {
        if(ind == n || k == 0) {
            return 0;
        }
        if(dp[ind][k] != -1) return dp[ind][k];
        
        int notTaken = solve(ind + 1, k, piles, dp);
        int ans = 0;
        
        for(int i = 0; i < piles[ind].size(); i++) {
            int taken = 0;
            if(k - i - 1 >= 0) {
                taken = piles[ind][i] + solve(ind + 1, k - i - 1, piles, dp);
            }
            
            ans = max(ans, taken);
        }
        
        return dp[ind][k] = max(ans, notTaken);
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < piles[i].size(); j++) {
                piles[i][j] += piles[i][j-1];
            }
        }
        vector<vector<int>> dp(n, vector<int> (k + 1, -1));
        
        return solve(0, k, piles, dp);
    }
};