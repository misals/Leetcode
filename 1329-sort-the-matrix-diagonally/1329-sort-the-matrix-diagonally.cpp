class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> v;
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> ans(n, vector<int> (m));
        
        int col = 0;
        int row = 0;
        int k = 0;
        
        for(int i = 0; i < n; i++) {
            vector<int> temp;
            int row = i;
            int col = 0;
            while(row < n && col < m) {
                temp.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(), temp.end());
            int k = 0;
            row = i;
            col = 0;
            while(row < n && col < m) {
                ans[row][col] = temp[k];
                row++;
                col++;
                k++;
            }
        }
        for(int j = 1; j < m; j++) {
            vector<int> temp;
            int row = 0;
            int col = j;
            while(row < n && col < m) {
                temp.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(temp.begin(), temp.end());
            int k = 0;
            row = 0;
            col = j;
            while(row < n && col < m) {
                ans[row][col] = temp[k];
                row++;
                col++;
                k++;
            }
        }
        return ans;
        
    }
};