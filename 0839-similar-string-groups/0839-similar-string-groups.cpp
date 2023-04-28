class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        
        vector<vector<int>> graph(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int cnt = 0;
                
                for(int k = 0; k < m; k++) {
                    if(strs[i][k] != strs[j][k]) {
                        cnt++;
                    }
                }
                
                if(cnt <= 2) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                
                vis[i] = 1;
                queue<int> q;
                q.push(i);

                while(!q.empty()) {
                    auto node = q.front();
                    q.pop();
                    
                    for(auto &it : graph[node]) {
                        if(!vis[it]) {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};