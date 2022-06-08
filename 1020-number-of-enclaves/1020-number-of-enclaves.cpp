class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &grid) {
        if(grid[i][j] == 1) {
            grid[i][j] = 0;
            
            if(i + 1 < grid.size()) {
                dfs(i + 1, j, grid);
            }
            if(i - 1 >= 0) {
                dfs(i - 1, j, grid);
            }
            if(j + 1 < grid[i].size()) {
                dfs(i, j + 1, grid);
            }
            if(j - 1 >= 0) {
                dfs(i, j - 1, grid);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            dfs(i, 0, grid);
            dfs(i, m-1, grid);
        }
        
        for(int j = 0; j < m; j++) {
            dfs(0, j, grid);
            dfs(n-1, j, grid);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};