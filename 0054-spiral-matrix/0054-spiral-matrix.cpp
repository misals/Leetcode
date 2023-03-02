class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        
        int left = 0;
        int right = m - 1;
        
        int up = 0;
        int down = n - 1;
        
        int dir = 0;
        
        while(left <= right && up <= down) {
            if(dir % 4 == 0) {
                for(int i = left; i <= right; i++) {
                    ans.push_back(matrix[up][i]);
                }
                up++;
            }
            else if(dir % 4 == 1) {
                for(int i = up; i <= down; i++) {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir % 4 == 2) {
                for(int i = right; i >= left; i--) {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            else if(dir % 4 == 3) {
                for(int i = down; i >= up; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
        }
        return ans;
        
    }
};