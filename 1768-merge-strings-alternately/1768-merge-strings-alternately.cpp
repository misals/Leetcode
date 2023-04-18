class Solution {
public:
    string mergeAlternately(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        int i = 0;
        int j = 0;
        
        string ans;
        
        while(i < n && j < m) {
            ans.push_back(s[i++]);
            ans.push_back(t[j++]);
        }
        while(i < n) {
            ans.push_back(s[i++]);
        }
        while(j < m) {
            ans.push_back(t[j++]);
        }
        return ans;
    }
};