class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(int i = 1; i < n; i++) {
            if(mp.find(nums[i] + nums[i-1]) != mp.end()) {
                return true;
            }
            mp[nums[i] + nums[i-1]] = i;
        }
        return false;
        
    }
};