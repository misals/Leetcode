class Solution {
public:
    void dfs(int node, int &cnt, vector<vector<int>> &adj, vector<int> &vis, map<int,int> &mp) {
        vis[node] = 1;
        mp[node] = 1;
        for(auto &it : adj[node]) {
            if(!vis[it]) {
                cnt++;
                dfs(it, cnt, adj, vis, mp);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n, 0);
        vector<long long> temp(n);
        
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                map<int, int> mp;
                int cnt = 1;
                dfs(i, cnt, adj, vis, mp);
                
                for(auto it : mp) {
                    temp[it.first] = n - cnt;
                }
                mp.clear();
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += temp[i];
        }
        return ans / 2;
    }
};