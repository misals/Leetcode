class Solution {
public:
    bool closeStrings(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if(n != m) return false;
        
        vector<int> ch1(26, 0);
        vector<int> ch2(26, 0);
        
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        
        for(int i = 0; i < n; i++) {
            ch1[s[i] - 'a'] = 1;
            ch2[t[i] - 'a'] = 1;
            
            v1[s[i] - 'a']++;
            v2[t[i] - 'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(ch1[i] != ch2[i]) {
                return false;
            }
        }
    
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        return v1 == v2;
    }
};