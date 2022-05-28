class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int x, y;
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] < mini) {
                mini = nums[i];
                x = i + 1;
            }
            if(nums[i] > maxi) {
                maxi = nums[i];
                y = i + 1;
            }
        }
        int ans = INT_MAX;
        ans = min(ans, max(x,y));
        ans = min(ans, n - min(x,y) + 1);
        ans = min(ans, min(x,y) + n - max(x,y) + 1);
        
        return ans;
    }
};