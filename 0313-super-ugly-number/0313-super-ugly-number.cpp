class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n);
        dp[0] = 1;
        
        int sz = primes.size();
        vector<int> dp1(sz, 0);
        
        for(int i = 1; i < n; i++) {
            long long mini = INT_MAX;
            
            for(int j = 0; j < sz; j++) {
                mini = min(mini, dp[dp1[j]] * primes[j]);
            }
            
            for(int j = 0; j < sz; j++) {
                if(mini == dp[dp1[j]] * primes[j])
                    dp1[j]++;
            }
            // if(dp[i-1] != mini) {
            //     dp[i] = mini;
            // }         
            // else {
            //     i--;
            // }
            dp[i] = mini;
        }
        return dp[n-1];
    }
};