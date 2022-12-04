class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long sum1 = 0;
        long long sum2 = 0;
        
        for(int i = 0; i < n; i++) sum2 += nums[i];
        
        int ans = INT_MAX;
        int ind = 0;
        
        for(int i = 0; i < n; i++) {
            sum1 += nums[i];
            sum2 -= nums[i];
            
            double num1 = sum1/(i+1);
            double num2;
            if(i != n-1)
                num2 = sum2/(n-i-1);
            else 
                num2 = 0;
            double n1 = round(num1);
            double n2 = round(num2);
            
            if(abs(n1 - n2) < ans) {
                ans = abs(n1 - n2);
                ind = i;
            }
        }
        return ind;
    }
};