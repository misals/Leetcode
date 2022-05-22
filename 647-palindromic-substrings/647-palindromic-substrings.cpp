class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        bool dp[n][n];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    dp[i][j] = true;
                }
            }
        }
        
        for(int diff = 0; diff < n; diff++) {
            for(int i = 0, j = diff; j < n; i++, j++) {
                if(diff == 0) {
                    dp[i][j] = true;
                } else if(diff == 1) {
                    if(s[i] == s[j]) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                } else {
                    if(s[i] == s[j] && dp[i+1][j-1] == true) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j >= i && dp[i][j] == true) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};