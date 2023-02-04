class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        
        int i = 0;
        int j = 0;
        
        int n = s1.size();
        int m = s2.size();
        
        if(n > m) {
            return false;
        }
        
        while(j < n) {
            v1[s1[j] - 'a']++;
            v2[s2[j] - 'a']++;
            j++;
        }
        j--;
        
        while(j < m) {
            if(v1 == v2) {
                return true;
            }
            j++;
            if(j != m) {
                v2[s2[j] - 'a']++;
            }
            v2[s2[i] - 'a']--;
            i++;
        }
        return false;
    }
};