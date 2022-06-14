class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n,0));
        
        for(int diff = 0; diff < n; diff++) {
            for(int i = 0, j = diff; j < n; i++, j++) {
                if(diff == 0) {
                    dp[i][j] = 1;
                } else if(diff == 1) {
                    if(s[i] == s[j]) {
                        dp[i][j] = 2;
                    } else {
                        dp[i][j] = 0;
                    }
                } else {
                    if(s[i] == s[j] && dp[i+1][j-1] > 0) {
                        dp[i][j] = 2 + dp[i+1][j-1];
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        int start = 0;
        int end = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(dp[i][j] > maxi) {
                    maxi = dp[i][j];
                    start = i;
                    end = j;
                }
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};