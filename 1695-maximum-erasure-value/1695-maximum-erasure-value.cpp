class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        
        int low = 0;
        int sum = 0;
        int pref[n+1];
        for(int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + nums[i];
        }
        
        for(int i = 0; i < n; i++) {
            if(mp.find(nums[i]) != mp.end()) {
                low = max(low, mp[nums[i]] + 1);
            }
            mp[nums[i]] = i;
            sum = max(sum, pref[i+1] - pref[low]);
        }
        return sum;
    }
};