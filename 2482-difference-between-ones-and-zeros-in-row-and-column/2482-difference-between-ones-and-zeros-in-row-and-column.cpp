class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ans(n, vector<int> (m));
        
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        
        for(int i = 0; i < n; i++) {
            int zero = 0;
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) zero++;
            }
            row[i] = zero;
        }
        
        for(int j = 0; j < m; j++) {
            int zero = 0;
            for(int i = 0; i < n; i++) {
                if(grid[i][j] == 0) zero++;
            }
            col[j] = zero;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[i][j] = ((m - row[i]) + (n - col[j]) - row[i] - col[j]);
            }
        }
        return ans;                         
    }
    
};