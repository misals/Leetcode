class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                nums[i] = -1;
            }
            sum += nums[i];
            if(sum == 0) {
                ans = max(ans, i + 1);
            } else if(mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return ans;
    }
};