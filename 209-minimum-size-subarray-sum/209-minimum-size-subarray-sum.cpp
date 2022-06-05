class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = 0;
        int sum = 0;
        int ans = INT_MAX;
        
        while(hi < n) {
            sum += nums[hi];
            if(sum >= target) {
                while(sum >= target) {
                    sum -= nums[lo];
                    lo++;
                }
                ans = min(ans, hi - lo + 2);
            }
            hi++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};