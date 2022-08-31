class Solution {
public:
    
    void dfs(vector<vector<int>> &mat, int i, int j, int prev, vector<vector<int>> &ocean) {
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size()) {
            return;
        }
        if(ocean[i][j] == 1) {
            return;
        }
        if(mat[i][j] < prev) {
            return;
        }
        
        ocean[i][j] = 1;
        
        dfs(mat, i + 1, j, mat[i][j], ocean);
        dfs(mat, i - 1, j, mat[i][j], ocean);
        dfs(mat, i, j + 1, mat[i][j], ocean);
        dfs(mat, i, j - 1, mat[i][j], ocean);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> ans;
        
        if(n == 0) {
            return ans;
        }
        
        vector<vector<int>> pacific(n, vector<int> (m, 0));
        vector<vector<int>> atlantic(n, vector<int> (m, 0));
        
        for(int i = 0; i < m; i++) {
            dfs(mat, 0, i, INT_MIN, pacific);
            dfs(mat, n - 1, i, INT_MIN, atlantic);
        }
        
        for(int i = 0; i < n; i++) {
            dfs(mat, i, 0, INT_MIN, pacific);
            dfs(mat, i, m - 1, INT_MIN, atlantic);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    vector<int> v(2);
                    v[0] = i;
                    v[1] = j;
                    ans.push_back(v);
                }
            }
        }
        
        return ans;
    }
};