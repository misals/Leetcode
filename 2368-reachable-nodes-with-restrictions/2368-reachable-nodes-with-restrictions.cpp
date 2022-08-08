class Solution {
public:
    void dfs(int node, vector<int> adj[], int &ans, vector<int> &vis) {
        ans++;
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, ans, vis);
            }
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        
        vector<int> adj[n];
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> vis(n, 0);
        int ans = 0;
        for(auto it : restricted) {
            vis[it] = 1;
        }
        dfs(0, adj, ans, vis);
        return ans;
    }
};