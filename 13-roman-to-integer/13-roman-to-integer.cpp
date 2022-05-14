class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['M'] = 1000;
        mp['D'] = 500;
        mp['C'] = 100;
        mp['L'] = 50;
        mp['X'] = 10;
        mp['V'] = 5;
        mp['I'] = 1;
        
        int n = s.size();
        
        int num = mp[s[n- 1]];
        for(int i = n - 2; i >= 0; i--) {
            if(mp[s[i]] < mp[s[i+1]]) {
                num = num - mp[s[i]];
            } else {
                num = num + mp[s[i]];
            }
        }
        return num;
    }
};