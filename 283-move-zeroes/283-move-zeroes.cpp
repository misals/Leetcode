class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                nums[low] = nums[i];
                low++;
            }
        }
        while(low < n) {
            nums[low] = 0;
            low++;
        }
    }
};