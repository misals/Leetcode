class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        
        int n = s.size();
        int m = p.size();
        
        if(m > n) {
            return ans;
        }
        int i = 0;
        int j = 0;
        
        while(j < m) {
            v1[s[j] - 'a']++;
            v2[p[j] - 'a']++;
            j++;
        }
        j--;
        
        
        while(j < n) {
            if(v1 == v2) {
                ans.push_back(j - (m - 1));
            }
            j++;
            if(j != n) {
                v1[s[j] - 'a']++;
            }
            v1[s[i] - 'a']--;
            i++;
        }
        return ans;
    }
};