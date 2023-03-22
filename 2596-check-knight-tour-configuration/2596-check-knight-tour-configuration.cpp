class Solution {
public:
    int n;
    int cnt = 0;
    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    
    bool isValid(int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= n) {
            return false;
        }
        return true;
    }
    
    void dfs(int x, int y, vector<vector<int>> &grid, int par) {
        if(isValid(x, y) == false || grid[x][y] != par + 1) return;
        
        int parVal = grid[x][y];
        grid[x][y] = 0;
        cnt++;
        for(int i = 0; i < 8; i++) {
            int a = x + dx[i];
            int b = y + dy[i];
            dfs(a, b, grid, parVal);
        } 
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        n = grid.size(); 
        dfs(0, 0, grid, -1);
        return cnt == n * n;
    }
};