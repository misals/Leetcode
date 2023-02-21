class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m) {
            return 0;
        }
        if(grid[i][j] == 0) {
            return 0;
        }
        int temp = grid[i][j];
        grid[i][j] = 0;
        
        int up = solve(i-1, j, grid, n, m);
        int down = solve(i+1, j, grid, n, m);
        int left = solve(i, j-1, grid, n, m);
        int right = solve(i, j+1, grid, n, m);
        
        grid[i][j] = temp;
        
        return grid[i][j] + max({up, down, left, right});
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) {
                    int val = solve(i, j, grid, n, m);
                    ans = max(ans, val);
                }
            }
        }
        
        return ans;
    }
};