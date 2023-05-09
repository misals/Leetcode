class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int left = 0;
        int right = m - 1;
        
        int up = 0;
        int down = n - 1;
        
        vector<int> ans;
        int dir = 0;
        
        while(left <= right && up <= down) {
            if(dir % 4 == 0) {
                for(int i = left; i <= right; i++) {
                    ans.push_back(mat[up][i]);
                }
                up++;
            }
            else if(dir % 4 == 1) {
                for(int i = up; i <= down; i++) {
                    ans.push_back(mat[i][right]);
                }
                right--;
            }
            else if(dir % 4 == 2) {
                for(int i = right; i >= left; i--) {
                    ans.push_back(mat[down][i]);
                }
                down--;
            }
            else if(dir % 4 == 3) {
                for(int i = down; i >= up; i--) {
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
            dir++;
        }
        return ans;
    }
};