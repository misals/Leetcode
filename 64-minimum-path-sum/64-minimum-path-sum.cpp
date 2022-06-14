class Solution {
public:
    int minPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m, 0);
        
        for(int i = 0; i < n; i++) {
            vector<int> temp(m, 0);
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    temp[j] = matrix[i][j];
                    continue;
                }
                int up = INT_MAX;
                int left = INT_MAX;
                if(i > 0) {
                    up = matrix[i][j] + prev[j];
                }
                if(j > 0) {
                    left = matrix[i][j] + temp[j-1];
                }
                temp[j] = min(up, left);
            }
            prev = temp;
        }
        return prev[m-1];
    }
};