class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n,vector<int>(n,0));
        vector<int>indegree(n,0);
        
        for(auto &road : roads){
            indegree[road[0]]++;
            indegree[road[1]]++;
            adj[road[0]][road[1]] = 1;
            adj[road[1]][road[0]] = 1;
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int network_rank = indegree[i] + indegree[j] - adj[i][j];
                ans = max(ans,network_rank);
            }
        }
        return ans;
    }
};