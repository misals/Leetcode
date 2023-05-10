class Solution {
public:
    bool checkValid(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for(int i = 0; i < n; i++) {
            set<int> row, col;
            for(int j = 0; j < n; j++) {
                row.insert(mat[i][j]);
                col.insert(mat[j][i]);
            }
            if(row.size() != n || col.size() != n) {
                return false;
            }
        }
        return true;
    }
};