class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            int m = matrix[i].size();
            if(target >= matrix[i][0] && target <= matrix[i][m-1]) {
                for(int j = 0; j < m; j++) {
                    if(target == matrix[i][j]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};