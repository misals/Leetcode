class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            long long val1 = nums[i];
            for(int j = i; j < n; j++) {
                long long val2 = nums[j];
                val1 = __gcd(val1, val2);
                if(val1 == k)
                    ans++;
            }
        }
        return ans;
    }
};