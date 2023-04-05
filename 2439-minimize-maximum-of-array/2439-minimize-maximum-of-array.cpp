class Solution {
public:
    bool isPossible(int k, vector<int> &nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            
            if(sum > (long)k * (i+1)) {
                return false;
            }
        }
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int low = 0;
        int high = 1e9;
        
        int ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(isPossible(mid, nums)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};