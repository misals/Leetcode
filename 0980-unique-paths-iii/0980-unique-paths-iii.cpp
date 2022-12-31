class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    int n, m;
    
    bool isValid(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }
    
    int dfs(int i, int j, int zero, pair<int, int> &dest, vector<vector<int>>& grid) {
        if(zero == -1 && pair<int, int>(i, j) == dest) {
            return 1;
        }
        grid[i][j] = -1;
        int ans = 0;
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(isValid(x, y) && grid[x][y] != -1) {
                ans += dfs(x, y, zero - 1, dest, grid);
            }
        }
        grid[i][j] = 0;
        
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        int zero = 0;
        
        pair<int, int> src, dest;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    zero++;
                }
                if(grid[i][j] == 1) {
                    src = {i, j};
                }
                if(grid[i][j] == 2) {
                    dest = {i, j};
                }
            }
        }
        
        return dfs(src.first, src.second, zero, dest, grid);
    }
};