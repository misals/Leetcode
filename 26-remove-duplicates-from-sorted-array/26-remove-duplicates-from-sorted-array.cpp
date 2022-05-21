class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        int i;
        for(i = 0; i < n - 1; i++) {
            if(nums[i] != nums[i+1]) {
                nums[low] = nums[i];
                low++;
            }
        }
        nums[low] = nums[i];
        low++;
        return low;
    }
};