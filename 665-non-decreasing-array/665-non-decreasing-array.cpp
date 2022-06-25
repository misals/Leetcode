class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int maxi = nums[0];
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i+1]) {
                if(i + 2 < n) {
                    if(nums[i] < nums[i+2]) {
                        nums[i+1] = nums[i];
                    }
                    else if(nums[i] > nums[i+2]) {
                        nums[i] = nums[i+1];
                    }
                    else {
                        nums[i+1] = nums[i];
                    }
                }
                else {
                    nums[i+1] = nums[i];
                }
                break;
            }
        }
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i+1])
                return false;
        }
        return true;
    }
};