class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> left(n);
        vector<int> right(n);
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            left[i] = maxi;
        }
        
        for(int i = n - 1; i >= 0; i--) {
            mini = min(mini, nums[i]);
            right[i] = mini;
        }
        
        int ans = 0;
        for(int i = 1; i < n - 1; i++) {
            if(left[i-1] < nums[i] && right[i+1] > nums[i]) {
                ans += 2;
            }
            else if(nums[i-1] < nums[i] && nums[i] < nums[i+1]) {
                ans++;
            }
        }
        return ans;
    }
};