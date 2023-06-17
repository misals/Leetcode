class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, int prev, int n, int m, vector<int>& arr1, vector<int>& arr2) 
    {
        if (i == n) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int num = 2001;    
        int idx = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if (arr1[i] > prev) 
            num = f(i + 1, idx, arr1[i], n, m, arr1, arr2);
        if (idx < m) 
            num = min(num, 1 + f(i + 1, idx + 1, arr2[idx], n, m, arr1, arr2));
        return dp[i][j] = num;
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();  
        sort(arr2.begin(), arr2.end());       
        dp.assign(n + 1, vector<int>(m + 1, -1));
        int result = f(0, 0, -1, n, m, arr1, arr2);
        return (result < 2001) ? result : -1; 
    }
};