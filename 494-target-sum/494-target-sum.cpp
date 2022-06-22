class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        if((sum-target < 0) || (sum - target) % 2) return false;
        
        int k = (sum-target) / 2;
        
        vector<int> prev(k+1, 0), curr(k+1, 0);
        
        if(nums[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        
        if(nums[0] != 0 && nums[0] <= k) prev[nums[0]] = 1;
        
        for(int ind = 1; ind < n; ind++) {
            for(int tar = 0; tar <= k; tar++) {
                int notPick = prev[tar];
                int pick = 0;
                if(tar >= nums[ind]) {
                    pick = prev[tar-nums[ind]];
                }
                curr[tar] = pick + notPick;
            }
            prev = curr;
        }
        return prev[k];
    }
};