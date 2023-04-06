class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> v;
        long long sum = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] < 0) {
                    neg++;
                }
                sum += abs(matrix[i][j]);
                v.push_back(abs(matrix[i][j]));
            }
        }
        if(neg % 2 != 0) {
            sort(v.begin(), v.end());
            sum -= v[0] * 2;
        }
        return sum;
    }
};