class Solution {
public:
    int numOfMinutes(int n, int h, vector<int>& m, vector<int>& info) {
        if(n==1){
            return 0;
        }
        vector<int>adj[n];
        for(int i=0; i<n; i++){
            if(m[i]==-1){
                continue;
            }
            else{
                adj[m[i]].push_back(i);
            }
        }
        queue<int>q;
        vector<int>sum(n,0);
        sum[h]=0;
        q.push(h);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: adj[node]){
                q.push(it);
                sum[it]=sum[node]+info[node];
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans,sum[i]);
        }
        return ans;
    }
};