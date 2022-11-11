class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 1;
        int prev = nums[0];
        int n = nums.size();
        
        
        
        for(int i = 1; i < n; i++) {
            if(nums[i] == prev) {
                
            }
            else {
                nums[low] = nums[i];
                low++;
                prev = nums[i];
            }
        }
        return low;
    }
};