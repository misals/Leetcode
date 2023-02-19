class Solution {
public:
    void findSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool &flag) {
        if(i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size()) {
            return;
        }
        if(grid2[i][j] == 0) {
            return;
        }
        if(grid2[i][j] == 1) {
            if(grid1[i][j] == 0) {
                flag = false;
                return;
            }
            grid2[i][j] = 0;
        }
        findSubIsland(grid1, grid2, i + 1, j, flag);
        findSubIsland(grid1, grid2, i - 1, j, flag);
        findSubIsland(grid1, grid2, i, j + 1, flag);
        findSubIsland(grid1, grid2, i, j - 1, flag);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        
        int n = grid1.size();
        int m = grid1[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid2[i][j] == 1) {
                    bool flag = true;
                    findSubIsland(grid1, grid2, i, j, flag);
                    if(flag) {
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};