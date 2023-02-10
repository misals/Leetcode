class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        
        if(q.size() == 0 || q.size() == n*n) {
            return -1;
        }
        
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};
        
        int dist = -1;
        while(!q.empty()) {
            int sz = q.size();
            
            for(int i = 0; i < sz; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int j = 0; j < 4; j++) {
                    int a = x + dx[j];
                    int b = y + dy[j];
                    
                    if(a >= 0 && a < n && b >= 0 && b < n && grid[a][b] == 0) {
                        grid[a][b] = 1;
                        q.push({a, b});
                    }
                }
            }
            dist++;
        }
        return dist;
    }
};