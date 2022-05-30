class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n];
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                dp[i][j] = 0;
            }
        }
        
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
        int x, y;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(dp[i][j] > maxi) {
                    maxi = dp[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        cout << x << " " << y  << " " << maxi<< endl;
        string ans = s.substr(x, y - x + 1);
        return ans;
    }
};



