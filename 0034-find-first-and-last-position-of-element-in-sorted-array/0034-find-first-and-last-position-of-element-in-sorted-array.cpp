class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2, -1);
        int n = nums.size();
        
        int lo = 0;
        int hi = n - 1;
        
        while(lo <= hi) {
            int mid =  (hi + lo)/2;
            if(nums[mid] == target) {
                v[0] = mid;
                hi = mid-1;
            }
            else if(nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        lo = 0;
        hi = n - 1;
    
         while(lo <= hi) {
            int mid = (hi + lo)/2;
            if(nums[mid] == target) {
                v[1] = mid;
                lo = mid+1;
            }
            else if(nums[mid] > target) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return v;
    }
};