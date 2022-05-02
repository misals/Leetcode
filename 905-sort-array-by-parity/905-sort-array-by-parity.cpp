class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        while(l <= h)
        {
            if(nums[l] % 2 != 0)
            {
                swap(nums[l], nums[h]);
                h--;
            }
            else
            {
                l++;
            }
        }
        return nums;
    }
};