class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int cntB = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == 'b') {
                cntB++;
            }
            if(s[i] == 'a' && cntB > 0) {
                cntB--;
                ans++;
            }
        }
        return ans;
    }
};