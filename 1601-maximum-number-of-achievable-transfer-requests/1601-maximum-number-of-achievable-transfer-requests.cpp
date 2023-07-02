class Solution {
public:
    void func(int idx , vector<vector<int>>& nums , vector<int> &indegree ,int n , int &ans , int curr){
        if(idx == nums.size()){
            int f = 1;
            for(int i = 0; i < n; i++){
                if(indegree[i] != 0){
                    f = 0;
                    break;
                }
            }
            if(f){
                ans = max(ans , curr);
            }
            return;
        }
        func(idx + 1 , nums , indegree , n , ans , curr);
        int u = nums[idx][0] , v = nums[idx][1];
        indegree[u]--;
        indegree[v]++;
        func(idx + 1 , nums , indegree , n , ans , curr + 1);
        indegree[u]++;
        indegree[v]--;
    }
    int maximumRequests(int n, vector<vector<int>>& nums) {
        vector<int> indegree(n , 0);
        int ans = 0;
        func(0 , nums , indegree , n , ans , 0);
        return ans;
    }
};