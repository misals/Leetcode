class Solution {
public:
    void maxAreaOfIsland(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &vis, int &count, int n, int m) {
        if(r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || grid[r][c] == 0) {
            return;
        }
        vis[r][c] = 1;
        count++;
        maxAreaOfIsland(r, c - 1, grid, vis, count, n, m);
        maxAreaOfIsland(r - 1, c, grid, vis, count, n, m);
        maxAreaOfIsland(r, c + 1, grid, vis, count, n, m);
        maxAreaOfIsland(r + 1, c, grid, vis, count, n, m);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int res = 0, count = 0;
        
        vector<vector<int>> vis(n, vector<int> (m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
            {
                if(vis[i][j] == 0) {
                    count = 0;
                    maxAreaOfIsland(i, j, grid, vis, count, n, m);
                    res = max(res, count);
                }
            }
        }
        return res;
    }
};