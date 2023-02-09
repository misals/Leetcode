class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2, -1);
        
        int low = 0;
        int high = n - 1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            cout << low << " " << mid << " " << high << endl;
        
            
            if(nums[mid] == target) {
                ans[0] = mid;
                high = mid - 1;
            }
            else if(target < nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        low = 0;
        high = n - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target) {
                ans[1] = mid;
                low = mid + 1;
            }
            else if(target < nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};