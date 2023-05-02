class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double ans = -1e6;;
        
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        ans = max(ans, sum/k);
        
        int n = nums.size();
        
        for(int i = k; i < n; i++) {
            sum += nums[i];
            sum -= nums[i-k];
            
            ans = max(ans, sum / k);
        }
        return ans;
    }
};