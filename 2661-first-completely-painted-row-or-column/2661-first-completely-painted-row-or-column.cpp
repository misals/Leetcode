class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int i,j,m=mat.size(),n=mat[0].size();
        vector<vector<int>> v(m*n);
        vector<int> r(m,0),c(n,0);
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                v[mat[i][j]-1] = {i,j};
            }
        }
        for(i = 0; i < m*n; i++){
            r[v[arr[i]-1][0]]++;
            c[v[arr[i]-1][1]]++;
            if(r[v[arr[i]-1][0]] == n)return i;
            if(c[v[arr[i]-1][1]] == m)return i;
        }
        return -1;
    }
};