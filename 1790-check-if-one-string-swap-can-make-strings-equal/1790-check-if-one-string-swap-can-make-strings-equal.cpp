class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        int n = s1.size();
        
        int ind1 = -1;
        int ind2 = -1;
        
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                ind1 = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(s1[i] != s2[i]) {
                ind2 = i;
                break;
            }
        }
        if(ind1 == -1) {
            return true;
        }
        swap(s2[ind1], s2[ind2]);
        return s1 == s2;
    }
};