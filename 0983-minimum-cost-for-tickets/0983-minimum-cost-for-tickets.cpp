class Solution {
public:
    int n;
    
    int solve(int ind, vector<int> &costs, vector<int> &days, vector<int> &dp) {
        if(ind >= n) {
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        
        int oneDay = costs[0] + solve(ind + 1, costs, days, dp);
        
        int i = ind;
        for(; i < n; i++) {
            if(days[i] >= days[ind] + 7) {
                break;
            }
        }
        int sevenDay = costs[1] + solve(i, costs, days, dp);
        
        for(; i < n; i++) {
            if(days[i] >= days[ind] + 30) {
                break;
            }

        }
        int thirtyDay = costs[2] + solve(i, costs, days, dp);
        
        return dp[ind] = min({oneDay, sevenDay, thirtyDay});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        
        vector<int> dp(n + 1, -1);
        int ans = solve(0, costs, days, dp);
        
        return ans;
    }
};