class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        int pref[n];
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                pref[i] = nums[i];
            }
            if(i > 0) {
                pref[i] = nums[i] + pref[i-1];
            }
            if(pref[i] == k) {
                cnt++;
            }
            if(mp.find(pref[i] - k) != mp.end()) {
                cnt += mp[pref[i]-k];
            }
            mp[pref[i]]++;
        }
        return cnt;
    }
};