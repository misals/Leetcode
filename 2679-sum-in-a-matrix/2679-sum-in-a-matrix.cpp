class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        int ans = 0;
        
        int m = nums[0].size();
        
        for(int j = 0; j < m; j++) {
            int maxi = 0;
            for(int i = 0; i < n; i++) {
                maxi = max(maxi, nums[i][j]);
            }
            ans += maxi;
        }
        return ans;
    }
};