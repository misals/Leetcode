class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        int dp[n];
        
        for(int i = n - 1; i >= 0; i--) {
            while(pq.size() && pq.top().second > i + k) {
                pq.pop();
            }
            dp[i] = nums[i];
            dp[i] += pq.size() ? pq.top().first : 0;
            pq.push({dp[i], i});
        }
        return dp[0];
    }
};