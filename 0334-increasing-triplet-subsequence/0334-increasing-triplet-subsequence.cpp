class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int pref[n];
        int suff[n];
        
        pref[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = min(pref[i-1], nums[i]);
        }
        
        suff[n-1] = nums[n-1];
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i+1], nums[i]);
        }
        
        for(int i = 1; i < n - 1; i++) {
            if(nums[i] > pref[i-1] && nums[i] < suff[i+1]) {
                return true;
            }
        }
        return false;
    }
};