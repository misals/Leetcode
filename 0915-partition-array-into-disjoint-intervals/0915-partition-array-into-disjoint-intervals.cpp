class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        int maxi = nums[0];
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            if(nums[i] < mini) {
                mini = maxi;
                ans = i;
            }
            maxi = max(maxi, nums[i]);
        }
        return ans + 1;
    }
};