class Solution {
public:
    bool helper(vector<int> &nums, int k, int n, int mid) {
        int i = 0;
        while(i < n) {
            if(nums[i] <= mid) {
                k--;
                i += 2;
            }
            else {
                i++;
            }
            if(k == 0) return true;
        }
        return k == 0;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int low = 1;
        int high = 1e9 + 1;
        int ans = INT_MAX;
        int n = nums.size();
        
        while(low <= high) {
            int mid = low + (high- low)/2;
            
            if(helper(nums, k, n, mid)) {
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