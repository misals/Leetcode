class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char,char> mp;
        set<char> st;
        for(int i = 0; i < n; i++) {
            if(mp.find(s[i]) == mp.end() && st.find(t[i]) == st.end()) {
                mp[s[i]] = t[i];
                st.insert(t[i]);
            } else if(mp.count(s[i]) == 0 && st.count(t[i])) {
                return false;
            } else if(mp[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};