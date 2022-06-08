class Solution {
public:
    bool isValid(int i, int j, int n, vector<vector<int>> &grid) {
        if(i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0) {
            return true;
        }
        return false;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) {
            return -1;
        }
        int n = grid.size();
        int ans = 0;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        int di[8] = {0, -1, -1, -1, 0, 1, 1, 1};
        int dj[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        
        while(!q.empty()) {
            int sz = q.size();
            ans++;
            
            for(int i = 0; i < sz; i++) {
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                if(x == n - 1 && y == n - 1) {
                    return ans;
                }
                
                for(int j = 0; j < 8; j++) {
                    int a = x + di[j];
                    int b = y + dj[j];
                    
                    if(isValid(a, b, n, grid)) {
                        grid[a][b] = 1;
                        q.push({a,b});
                    }
                }
            }
        }
        return -1;
    }
};