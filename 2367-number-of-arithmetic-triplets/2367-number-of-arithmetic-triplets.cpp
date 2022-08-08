class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int num1 = nums[j] - nums[i];
                for(int k = j + 1; k < n; k++) {
                    int num2 = nums[k] - nums[j];
                    if(num1 == diff && num2 == diff) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};