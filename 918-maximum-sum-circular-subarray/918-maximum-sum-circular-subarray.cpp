class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int miniSum = INT_MAX;
        int totalSum = 0;
        int tempSum = 0;
        int cnt = 0;
        int maxiSum = INT_MIN;
        int tempSum1 = 0;
        
        
        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
            tempSum = tempSum + nums[i];
            if(tempSum < miniSum)
                miniSum = tempSum;
            if(tempSum > 0)
                tempSum = 0;
            
            tempSum1 += nums[i];
            if(tempSum1 > maxiSum)
                maxiSum = tempSum1;
            if(tempSum1 < 0)
                tempSum1 = 0;
            
            if(nums[i] < 0)
                cnt++;
        }
        if(cnt == n)
            return maxiSum;
        return max(maxiSum, totalSum - miniSum);
    }
};