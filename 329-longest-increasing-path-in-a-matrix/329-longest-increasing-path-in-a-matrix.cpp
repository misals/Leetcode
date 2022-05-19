class Solution {
public:
    int ans = 0;
    int di[4] = {0, -1, 0, 1};
    int dj[4] = {-1, 0, 1, 0};
    vector<vector<int>> dp;
    int checkAllPath(int x, int y, vector<vector<int>> &matrix,int N,int M) {
        if(dp[x][y] > 0)
            return dp[x][y];
        int cnt=1;
        for(int i=0;i<4;i++){
            int X=x+di[i];
            int Y=y+dj[i];
            if(X<0 || X>=N || Y<0 || Y>=M)
                continue;
            if(matrix[X][Y]<=matrix[x][y])
                continue;
            cnt=max(cnt,1+checkAllPath(X,Y,matrix,N,M));
        }
        return dp[x][y]=cnt;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        dp = vector<vector<int>>(n,vector<int>(m,0));
        for(int i = 0; i < n; i++) {
            m = matrix[i].size();
            for(int j = 0; j < m; j++) {
                ans = max(ans, checkAllPath(i, j, matrix, n, m));
            }
        }
        return ans;
    }
};