class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if(sum % 2 != 0 || n == 1) {
            return false;
        }
        if(n == 2) {
            return nums[0] == nums[1];
        }
        int k = sum / 2;
        vector<bool> prev(k + 1, 0), curr(k + 1, 0);
        prev[0] = prev[nums[0]] = true;
        curr[0] = true;
        
        for(int ind = 1; ind < n; ind++) {
            for(int target = 1; target <= k; target++) {
                bool notPick = prev[target];
                bool pick = false;
                if(target >= nums[ind]) {
                    pick = prev[target - nums[ind]];
                }
                curr[target] = pick | notPick;
            }
            prev = curr;
        }
        return prev[k];
    }
};