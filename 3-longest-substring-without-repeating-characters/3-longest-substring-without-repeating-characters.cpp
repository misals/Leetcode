class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        map<char,int> mp;
        int n = s.size();
        int low = 0;
        
        for(int i = 0; i < n; i++) {
            if(mp.find(s[i]) != mp.end()) {
                low = max(low, mp[s[i]] + 1);
            }
            mp[s[i]] = i;
            ans = max(ans, i - low + 1);
        }
        return ans;
    }
};