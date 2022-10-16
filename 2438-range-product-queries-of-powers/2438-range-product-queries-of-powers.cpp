class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& q) {
        int num = 0;
        vector<int> v;
        
        for(int i = 30; i >= 0; i--) {
            int num = 1 << i;
            if(n >= num) {
                v.push_back(num);
                n -= num;
            }
        }
        sort(v.begin(), v.end());
        int sz = v.size();
    
        vector<int> ans;
        
        
        for(int i = 0; i < q.size(); i++) {
            int l = q[i][0];
            long p = v[l++];
            while(l <= q[i][1]){
                p = (p * v[l++]) % mod;
            }
            ans.push_back(p);
        }
        
        return ans;
    }
};