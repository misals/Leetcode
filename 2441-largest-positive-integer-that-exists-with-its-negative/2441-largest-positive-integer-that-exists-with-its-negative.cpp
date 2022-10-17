class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1000; i >= 1; i--) {
            bool pos = false;
            bool neg = false;
            
            for(int j = 0; j < n; j++) {
                if(abs(nums[j]) == i) {
                    if(nums[j] < 0) {
                        neg = true;
                    }
                    if(nums[j] > 0) {
                        pos = true;
                    }
                }
                if(pos && neg) return i;
            }
        }
        return -1;
    }
};