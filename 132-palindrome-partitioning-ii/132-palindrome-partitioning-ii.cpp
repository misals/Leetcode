class Solution {
public:
    int findCuts(int i, int n, string &s, vector<int> &dp) {
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];
        int minCost = INT_MAX;
        for(int j = i; j < n; j++) {
            if(isPalindrome(i, j, s)) {
                int cost = 1 + findCuts(j + 1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
    
    bool isPalindrome(int start, int end, string &s) {
        while(start < end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return findCuts(0, n, s, dp) - 1;
    }
};