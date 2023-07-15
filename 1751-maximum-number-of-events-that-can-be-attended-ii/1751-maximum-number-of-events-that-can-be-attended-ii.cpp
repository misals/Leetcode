class Solution {
public:
    int helper(int index, vector<vector<int>>& events, int k, vector<vector<int>>&dp){
        if(index>=events.size()||k==0)return 0;
        if(dp[index][k]!=-1)return dp[index][k];
        int ans = helper(index+1,events,k,dp);
        int j=events.size();
        for(int i = index+1; i<events.size(); i++){
            if(events[i][0]>events[index][1]){
                j=i;
                break;
            }
        }
        ans=max(ans,events[index][2]+helper(j,events,k-1,dp));
        return dp[index][k]=ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
        return helper(0,events,k,dp);
    }
};