class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n));
        
        int up = 0;
        int down = n - 1;
        
        int left = 0;
        int right = n - 1;
        
        int dir = 0;
        int cnt = 1;
        
        while(left <= right && up <= down) {
            if(dir % 4 == 0) {
                for(int i = left; i <= right; i++) {
                    ans[up][i] = cnt;
                    cnt++;
                }
                up++;
            }
            else if(dir % 4 == 1) {
                for(int i = up; i <= down; i++) {
                    ans[i][right] = cnt;
                    cnt++;
                }
                right--;
            }
            else if(dir % 4 == 2) {
                for(int i = right; i >= left; i--) {
                    ans[down][i] = cnt;
                    cnt++;
                }
                down--;
            }
            else if(dir % 4 == 3) {
                for(int i = down; i >= up; i--) {
                    ans[i][left] = cnt;
                    cnt++;
                }
                left++;
            }
            dir++;
        }
        return ans;
        
    }
};