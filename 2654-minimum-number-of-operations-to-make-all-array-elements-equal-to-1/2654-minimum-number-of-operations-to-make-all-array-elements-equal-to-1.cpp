class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                cnt++;
            }
        }
        if(cnt >= 1) return n - cnt;
        
        for(int i = 0; i < n; i++) {
            int gcdVal = nums[i];
            for(int j = i + 1; j < n; j++) {
                gcdVal = __gcd(gcdVal, nums[j]);
                
                if(gcdVal == 1) {
                    ans = min(ans, j - i + (n - 1));
                    break;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};