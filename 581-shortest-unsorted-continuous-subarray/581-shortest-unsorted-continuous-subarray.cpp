class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int end = -1;
        int maxi = nums[0];
        for(int i = 1; i < n; i++)
        {
            if(nums[i] < maxi)
                end = i;
            else
                maxi = nums[i];
        }
        
        int st = 0;
        int mini = nums[n-1];
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] > mini)
                st = i;
            else
                mini = nums[i];
        }
        return end - st + 1;
    }
};