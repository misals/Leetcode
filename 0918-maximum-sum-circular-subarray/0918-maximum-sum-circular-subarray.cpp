class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int tempSum1 = 0;
        int tempSum2 = 0;
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
            
            tempSum1 += nums[i];
            if(tempSum1 < mini) {
                mini = tempSum1;
            }
            if(tempSum1 > 0) {
                tempSum1 = 0;
            }
            
            tempSum2 += nums[i];
            if(tempSum2 > maxi) {
                maxi = tempSum2;
            }
            if(tempSum2 < 0) {
                tempSum2 = 0;
            }
            
            if(nums[i] < 0) {
                cnt++;
            }
        }
        if(cnt == n) return maxi;
        
        return max(maxi, totalSum - mini);
    }
};