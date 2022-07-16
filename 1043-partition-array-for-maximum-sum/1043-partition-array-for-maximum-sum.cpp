class Solution {
public:
    int maxSum(int ind, int n, int k, vector<int> &arr, vector<int> &dp) {
        if(ind == n) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        
        for(int j = ind; j < min(ind + k, n); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = maxi * len + maxSum(j + 1, n, k, arr, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[ind] = maxAns;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<int> dp(n, -1);
        return maxSum(0, n, k, arr, dp);
    }
};