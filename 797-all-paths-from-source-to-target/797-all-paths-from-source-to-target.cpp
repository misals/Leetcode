class Solution {
public:
    void dfs(int node, vector<vector<int>> &graph, vector<int> temp, vector<vector<int>> &ans) {
        temp.push_back(node);
        if(node == graph.size() - 1) {
            ans.push_back(temp);
        } else {
            for(auto it : graph[node]) {
                dfs(it, graph, temp, ans);
            }
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        
        if(graph.size() == 0) {
            return ans;
        }
        vector<int> temp;
        dfs(0, graph, temp, ans);
        
        return ans;
    }
};