class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prev1 = nums[0];
        int prev2;
        
        for(int ind = 1; ind < n; ind++) {
            int notPick = prev1;
            int pick = nums[ind];
            if(ind - 2 >= 0 ) {
                pick += prev2;
            }

            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        
        
        return prev1;
    }
};