class Solution {
public:
    int di[4] = {0,-1,0,1};
    int dj[4] = {-1,0,1,0};
    
    bool isValid(int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i >= n || j >= m) {
            return false;
        }
        return true;
    }
    
    void dfs(int x, int y, vector<vector<char>>& grid,  vector<vector<int>> &vis, queue<pair<int,int>> &q, int n, int m) {
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            int a = x + di[i];
            int b = y + dj[i];
            if(isValid(a, b, n, m) && vis[a][b] == 0 && grid[a][b] == '1') {
                dfs(a, b, grid, vis, q, n, m);
            }
        }
        return;
    }
    
    void findAll(vector<vector<char>>& grid,  vector<vector<int>> &vis, queue<pair<int,int>> &q, int &ans, int n, int m) {
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
            
            if(vis[x][y] == 0) {
                ans++;
                dfs(x, y, grid, vis, q, n, m);
            }
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    q.push({i,j});
                }
            }
        }
        
        int ans = 0;
        findAll(grid, vis, q, ans, n, m);
        
        return ans;
    }
};