class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int cnt = 0;
        int prefixSum = 0;
        mp[0] = 1;
        
        for(int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int mod = (prefixSum % k + k) % k;
            
            if(mp.find(mod) != mp.end()) {
                cnt += mp[mod];
            }
            mp[mod]++;
        }
        return cnt;
    }
};