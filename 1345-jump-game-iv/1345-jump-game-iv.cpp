class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int, vector<int>> mp;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        vector<bool> vis(n);
        vis[0] = true;
        
        queue<int> q;
        q.push(0);
        
        int ans = 0;
        
        while(!q.empty()) {
            int sz = q.size();
            
            for(int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                
                if(node == n - 1) return ans;
                
                vector<int> &temp = mp[arr[node]];
                temp.push_back(node - 1);
                temp.push_back(node + 1);
                
                for(auto it : temp) {
                    if(it >= 0 && it < n && vis[it] == false) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
                mp[arr[node]].clear();
            }
            ans++;
        }
        return ans;
        
    }
};