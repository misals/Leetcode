class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i-1] ) {
                if(cnt == 1) 
                    return false;
                cnt++;
                if(i < 2 || nums[i-2] <= nums[i]) {
                    nums[i-1] = nums[i];
                }
                else {
                    nums[i] = nums[i-1];
                }
            }
        }
        return true;
    }
};