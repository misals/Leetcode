class Solution {
public:
    int dp[2001][2001];
    bool solve(vector<int>& stones, int k, int i, unordered_map<int, int> &mp) {
        if(k <= 0) {
            return false;
        }
        if(mp.find(k + stones[i-1]) == mp.end()) {
            return false;
        } else {
            i = mp[k + stones[i-1]];
        }
        if(dp[i][k] != -1) {
            return dp[i][k];
        }
        if(i == stones.size() - 1) {
            return true;
        }
        
        dp[i][k] = solve(stones, k - 1, i+1, mp) || solve(stones, k, i+1, mp) || solve(stones, k +1, i+1, mp);
        return dp[i][k];
    }
    
    bool canCross(vector<int>& stones) {
        int i = 1; 
        int k = 1;
        memset(dp, -1, sizeof(dp));
        
        unordered_map<int, int> mp;
        for(int i = 0; i < stones.size(); i++) {
            mp.insert({stones[i], i});
        }
        
        if(stones[1] != 1) {
            return false;
        }
        
        return solve(stones, k, i, mp);
    }
};