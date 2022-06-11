class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> mp;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            mp[sum] = i;
        }
        int target = sum - x;
        if(target < 0 || x > sum) {
            return -1;
        }
        int res = INT_MIN;
        int num = 0;
        mp[0] = -1;
        for(int i = 0; i < n; i++) {
            num += nums[i];
            if(mp.find(num - target) != mp.end()) {
                res = max(res, i - mp[num - target]);
            }
        }
        return res == INT_MIN ? -1 : n - res;
    }
};