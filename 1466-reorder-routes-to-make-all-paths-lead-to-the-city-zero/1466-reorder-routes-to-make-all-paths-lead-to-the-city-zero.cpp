class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        set<pair<int,int>> st;
        
        for(auto &it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
            st.insert({it[0], it[1]});
        }
        
        int cnt = 0;
        vector<int> vis(n, 0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            int sz = q.size();
            
            for(int i = 0; i < n; i++) {
                int node = q.front();
                q.pop();
                
                for(auto it : adj[node]) {
                    if(vis[it] == 0) {
                        vis[it] = 1;
                        
                        if(!st.count({it, node})) {
                            cnt++;
                        }
                        
                        q.push(it);
                    }
                }
            }
        }
        
       return cnt; 
    }
};