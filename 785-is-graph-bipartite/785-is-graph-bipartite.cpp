class Solution {
public:
    bool checkBipartite(int node, vector<vector<int>>& graph, vector<int> &color) {
        if(color[node] == -1) color[node] = 1;
        
        for(auto it : graph[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                if(!checkBipartite(it, graph, color)) {
                    return false;
                }
            }
            else if(color[it] == color[node]) {
                return false;
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