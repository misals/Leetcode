class Solution {
public:
    int countHousePlacements(int n) {
        vector<long long> dp(n+1);
        dp[0] = 1;
        int mod = 1e9 + 7;
        for(int i = 1; i <= n; i++) {
            if(i == 1) {
                dp[i] = dp[i-1] + 1;
            }
            else {
                dp[i] = dp[i-1] + dp[i-2];
            }
            dp[i] %= mod;    
        }  
        return (dp[n] * dp[n]) % mod;
    }
};