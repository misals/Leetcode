class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        int n = words.size();
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            mp[words[i]]++;
        }
        bool flag = true;
        for(int i = 0; i < n; i++) {
            string s = words[i];
            if(s[0] == s[1]) {
                if(mp[s] % 2 == 0) {
                    ans += mp[s] * 2;
                }
                else if(flag) {
                    ans += mp[s] * 2;
                    flag = false;
                }
                else {
                    mp[s]--;
                    ans += mp[s] * 2;
                }
                mp[s] = 0;
            }
            else {
                string t = words[i];
                swap(t[0], t[1]);
                
                if(mp[s] > 0 && mp[t] > 0) {
                    ans += 4;
                    mp[s]--;
                    mp[t]--;
                }
            }
        }
        return ans;
    }
};