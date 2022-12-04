class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, int &ans) {
        vis[node] = 1;
        for(auto &it : adj[node]) {
            int currNode = it.first;
            int currVal = it.second;
            ans = min(ans, currVal);
            
            if(vis[currNode]) {
                continue;
            }
            dfs(currNode, adj, vis, ans);
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto &it : roads) {
            adj[it[0]-1].push_back({it[1]-1, it[2]});
            adj[it[1]-1].push_back({it[0]-1, it[2]});
        }
        
        int ans = INT_MAX;
        vector<int> vis(n, 0);
        
        dfs(0, adj, vis, ans);
        
        return ans;
    }
};