class Solution {
public:
    int fun(vector<int>& a, vector<int>& b) {
        int sum = 0, runningSum = 0, maxi = 0;
        sum = accumulate(a.begin(), a.end(), 0);
        int n = a.size();
        for(int i = 0; i < n; i++) {
            runningSum += b[i] - a[i];
            if(runningSum < 0)
                runningSum = 0;
            maxi = max(maxi, runningSum);
        }
        return sum + maxi;
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(fun(nums1, nums2), fun(nums2, nums1));
    }
};