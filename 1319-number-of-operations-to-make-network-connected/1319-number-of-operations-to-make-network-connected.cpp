class Solution {
public:
    void dfs(int node, vector<vector<int>> &arr, vector<int> &vis) {
        vis[node] = 1;
        for(auto &it : arr[node]) {
            if(!vis[it]) {
                dfs(it, arr, vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& nums) {
        if(nums.size() < n - 1) return -1;
        
        vector<vector<int>> arr(n);
        
        for(auto &it : nums) {
            arr[it[0]].push_back(it[1]);
            arr[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n, 0);
        int cnt = -1;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, arr, vis);
            }
        }
        return cnt;
    }
};