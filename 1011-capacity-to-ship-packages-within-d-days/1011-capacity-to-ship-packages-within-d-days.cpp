class Solution {
public:
    bool check(int capacity, vector<int> &nums, int days, int n) {
        int cnt = 1;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            if(sum + nums[i] <= capacity) {
                sum += nums[i];
            }
            else if(nums[i] > capacity) {
                return false;
            }
            else {
                cnt++;
                sum = nums[i];
            }
        }
        if(cnt <= days) {
            return true;
        }
        return false;
    }
    
    int shipWithinDays(vector<int>& nums, int days) {
        int sum = 0;
        int n = nums.size();
        int maxi = 0;
        for(auto it : nums) {
            sum += it;
            maxi = max(maxi, it);
        }
        int low = maxi;
        int high = sum;
        int ans = sum;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(check(mid, nums, days, n)) {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};