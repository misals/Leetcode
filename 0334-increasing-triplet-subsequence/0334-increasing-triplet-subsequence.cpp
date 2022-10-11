class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        int mini = INT_MAX;
        int mid = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > mid) {
                return true;
            }
            
            if(nums[i] > mini && nums[i] < mid) {
                mid = nums[i];
            }
            
            if(nums[i] < mini) {
                mini = nums[i];
            }
        }
        
        return false;
    }
};