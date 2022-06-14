class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sz = nums.size();
        int start = 0, end = 1, sum = 0;
        
        for(int i = 1; i < sz; i++) {
            int diff = nums[end] - nums[start];
            while(i + 1 < sz && nums[i+1] - nums[i] == diff) {
                end++;
                i++;
            }
            int n = end - start + 1;
            if(n >= 3) {
                sum += (n-2)*(n+1-2) / 2;
            }
            start = end;
            end++;
        }
        return sum;
    }
};