class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        int cnt = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(y - 1 >= 0) {
                    if(grid[x][y-1] == 1) {
                        grid[x][y-1] = 2;
                        q.push({x,y-1});
                    }
                }
                if(x - 1 >= 0) {
                    if(grid[x-1][y] == 1) {
                        grid[x-1][y] = 2;
                        q.push({x-1,y});
                    }
                }
                if(y + 1 < m) {
                    if(grid[x][y+1] == 1) {
                        grid[x][y+1] = 2;
                        q.push({x,y+1});
                    }
                }
                if(x + 1 < n) {
                    if(grid[x+1][y] == 1) {
                        grid[x+1][y] = 2;
                        q.push({x+1,y});
                    }
                }
            }
            if(!q.empty()) {
                cnt++;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return cnt;
    }
};