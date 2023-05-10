class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        map<int, pair<int, int>> mp;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        
        map<int, int> row, col;
        
        int sz = arr.size();
        
        for(int ind = 0; ind < sz; ind++) {
            int i = mp[arr[ind]].first;
            int j = mp[arr[ind]].second;
            
            row[i]++;
            col[j]++;
            
            if(row[i] == m || col[j] == n) {
                return ind;
            }
        }
        
        return -1;
    }
};