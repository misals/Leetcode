class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        
        int c = cuts.size();
        vector<vector<int>> dp(c+5, vector<int> (c+5, 0));
        
        for(int i = c; i >= 1; i--) {
            for(int j = 1; j <= c-2; j++) {
                if(i > j) {
                    continue;
                }
                long long mini = INT_MAX;
                for(int ind = i; ind <= j; ind++) {
                    long long cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1]  + dp[ind+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[1][c-2];
    }
};