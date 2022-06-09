class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n+1);
        prefix[0] = 0;
        
        for(int i = 0; i < n ; i++) {
            prefix[i+1] = prefix[i] ^ arr[i];
        }
        
        int m = queries.size();
        vector<int> ans;
        for(int i = 0; i < m; i++) {
            ans.push_back(prefix[queries[i][1] + 1] ^ prefix[queries[i][0]]);
        }
        return ans;
    }
};