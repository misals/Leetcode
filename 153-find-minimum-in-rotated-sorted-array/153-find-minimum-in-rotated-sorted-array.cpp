class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int res = nums[0];
        
        while(low <= high) {
            if(nums[low] <= nums[high]) {
                res = min(res, nums[low]);
            }
            
            int mid = low + (high - low) / 2;
            res = min(res, nums[mid]);
            
            if(nums[low] <= nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};