class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    int n, m;
    
    bool isValid(int i, int j) {
        if(i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }
        return true;
    }
    
    void dfs(int x, int y, vector<vector<int>> &grid) {
        grid[x][y] = 1;
        
        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if(isValid(newX, newY) && grid[newX][newY] == 0) {
                dfs(newX, newY, grid);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 0) {
                    dfs(i, j, grid);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};