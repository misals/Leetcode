class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > reach) {
                break;
            }
            reach = max(reach, i + nums[i]);
        }
        if(reach >= n - 1) {
            return true;
        }
        return false;
    }
};