class Solution {
public:
    bool isValid(int i, int j, int n, vector<vector<int>> &grid) {
        if(i >= 0 && i < n && j >= 0 && j < n && grid[i][j] == 0) {
            return true;
        }
        return false;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) {
            return -1;
        }
        vector<vector<int>> dir{{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int ans = 0;
        
        while(!q.empty()) {
            int sz = q.size();
            ans++;
            for(int i = 0; i < sz; i++) {
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                
                if(x == n - 1 && y == n - 1) {
                    return ans;
                }
                
                for(int j = 0; j < dir.size(); j++) {
                    int a = x + dir[j][0];
                    int b = y + dir[j][1];
                    
                    if(isValid(a, b, n, grid) == true) {
                        q.push({a,b});
                        grid[a][b] = 1;
                    }
                }
            }
        }
        return -1;
    }
};