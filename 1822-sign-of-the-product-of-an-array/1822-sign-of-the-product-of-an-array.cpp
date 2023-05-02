class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                return 0;
            }
            if(nums[i] < 0) {
                cnt++;
            }
        }
        if(cnt % 2 == 0) {
            return 1;
        }
        return -1;
    }
};