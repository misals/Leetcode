class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(target < nums[0])
            return 0;
        if(target > nums[n - 1])
            return n;
        
        int low = 0;
        int high = n - 1;
        while(low <= high)
        {
            long long mid = low + (high-low) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};