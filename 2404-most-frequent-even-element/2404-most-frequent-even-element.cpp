class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[nums[i]]++;
        
        int ans = -1;
        int maxi = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) {
                if(mp[nums[i]] > maxi) {
                    ans = nums[i];
                    maxi = mp[nums[i]];
                }
            }
        }
        
        return ans;
    }
};