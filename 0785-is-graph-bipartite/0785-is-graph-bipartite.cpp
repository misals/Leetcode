class Solution {
public:
    bool checkBipartite(int node, vector<vector<int>>& graph, vector<int> &color) {
        queue<int> q;
        color[node] = 1;
        q.push(node);
        
        while(!q.empty()) {
            int par = q.front();
            q.pop();
            
            for(auto it : graph[par]) {
                if(color[it] == -1) {
                    color[it] = 1 - color[par];
                    q.push(it);
                }
                else if(color[it] == color[par]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);
        
        for(int i = 0; i < v; i++) {
            if(color[i] == -1) {
                if(!checkBipartite(i, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};