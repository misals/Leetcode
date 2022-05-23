class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> mp(256, -1);
        int low = 0, high = 0;
        int ans = 0;
        while(high < n) {
            if(mp[s[high]] != -1) {
                low = max(low, mp[s[high]] + 1);
            }
            mp[s[high]] = high;
            ans = max(ans, high - low + 1);
            high++;
        }
        return ans;
    }
};