class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> ans;
        if(n < m) {
            return ans;
        }
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        
        for(int i = 0; i < m; i++) {
            v1[s[i] - 'a']++;
            v2[p[i] - 'a']++;
        }
        if(v1 == v2) {
            ans.push_back(0);
        }
        for(int i = m; i < n; i++) {
            v1[s[i] - 'a']++;
            v1[s[i-m] - 'a']--;
            if(v1 == v2) {
                ans.push_back(i-m+1);
            }
        }
        return ans;
        
    }
};