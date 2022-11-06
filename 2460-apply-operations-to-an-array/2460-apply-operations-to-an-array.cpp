class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
            if(nums[i] == 0)
                cnt++;
        }
        if(nums[n-1] == 0)
            cnt++;
        int low = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                nums[low] = nums[i];
                low++;
            }
        }
        int i = n - 1;
        while(cnt--) {
            nums[i] = 0;
            i--;
        }
        return nums;
    }
};