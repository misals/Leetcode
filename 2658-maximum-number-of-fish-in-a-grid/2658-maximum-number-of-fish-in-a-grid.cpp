class Solution {
public:
    int m, n;
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    
    bool isValid(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }
    
    void solve(int x, int y, int &val, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        val = val + grid[x][y];
        
        //cout << x << " " << y << endl;
        
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if(isValid(newX, newY) && grid[newX][newY] != 0 && vis[newX][newY] == 0) {
                solve(newX, newY, val, grid, vis);
            }
        }
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0 && vis[i][j] == 0) {
                    int val = 0;
                    solve(i, j, val, grid, vis);
                    ans = max(ans, val);
                }
            }
        }
        return ans;
    }
};