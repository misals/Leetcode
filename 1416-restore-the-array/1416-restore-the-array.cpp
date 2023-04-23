class Solution {
public:
    int mod = 1e9 + 7;
    
    int solve(int ind, string &s, int k, vector<int> &dp) {
        if(ind == s.size()) {
            return 1;
        }
        if(dp[ind] != -1) return dp[ind];
        
        if(s[ind] == '0') return 0;
        
        long long num = 0;
        int ans = 0;
        for(int i = ind; i < s.size(); i++) {
            
            num = num * 10 + (s[i] - '0');
            if(num > k) {
                break;
            }
            ans += solve(i + 1, s, k, dp);
            ans %= mod;
        }
        return dp[ind] = ans;
    }
    
    int numberOfArrays(string s, int k) {
        int n = s.size();
        
        vector<int> dp(n+1, -1);
        
        return solve(0, s, k, dp);
    }
};