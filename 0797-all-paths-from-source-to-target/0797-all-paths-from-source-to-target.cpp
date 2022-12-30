class Solution {
public:
    void dfs(int node, vector<int> &temp, vector<vector<int>> &ans, vector<vector<int>> &adj, int n) {
        if(node == n-1) {
            ans.push_back(temp);
            return;
        }
        for(auto it : adj[node]) {
            temp.push_back(it);
            dfs(it, temp, ans, adj, n);
            temp.pop_back();
            
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < n; i++) {
            int sz = graph[i].size();
            for(int j = 0; j < sz; j++) {
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        dfs(0, temp, ans, adj, n);
        
        return ans;
    }
};