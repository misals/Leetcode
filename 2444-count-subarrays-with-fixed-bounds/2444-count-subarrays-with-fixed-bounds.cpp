class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long cnt = 0;
        int n = nums.size();    
        
        int mini = -1;
        int maxi = -1;
        int start = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == minK) {
                mini = i;
            }
            if(nums[i] == maxK) {
                maxi = i;
            }
            if(nums[i] < minK || nums[i] > maxK) {
                mini = maxi = -1;
                start = i + 1;
            }
            cnt += max(0, min(mini, maxi) - start + 1);
        }
        return cnt;
    }
};