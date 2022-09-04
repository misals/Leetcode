class Solution {
public:
    int ans = 0;
    
    int checkCovered(vector<vector<int>> &mat) {
        int cnt = 0;
        for(int i = 0; i < mat.size(); i++) {
            int temp = 0;
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 0) {
                    temp++;
                }
            }
            if(temp == mat[i].size()) {
                cnt++;
            }
        }
        return cnt;
    }
    
    
    int solve(int ind, vector<vector<int>> &mat, int cols) {
        if(ind == mat[0].size() || cols == 0) {
            int temp = checkCovered(mat);
            ans = max(ans, temp);
            return temp;
        }
        int x = solve(ind + 1, mat, cols);
        vector<vector<int>> cmat = mat;
        for(int i = 0; i < cmat.size(); i++) {
            cmat[i][ind] = 0;
        }
        int y = solve(ind + 1, cmat, cols - 1);
        
        return max(x, y);
    }
    
    int maximumRows(vector<vector<int>>& mat, int cols) {
        
        solve(0, mat, cols); 
        return ans;
    }
};