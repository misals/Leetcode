class Solution {
public:
    int di[4] = {0, -1, 0, 1};
    int dj[4] = {-1, 0, 1, 0};
    
    bool isValid(int i, int j, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }
    
    
    void dfs(int x, int y, int n, int m, int &cnt, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if(isValid(x, y, n, m) && grid[x][y] == 1 && vis[x][y] == 0) {
            cnt++;
            vis[x][y] = 1;
            for(int i = 0; i < 4; i++) {
                int a = x + di[i];
                int b = y + dj[i];
                dfs(a, b, n, m, cnt, grid, vis);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    int cnt = 0;
                    dfs(i, j, n, m, cnt, grid, vis);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};