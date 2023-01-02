class Solution {
public:
    bool detectCapitalUse(string s) {
        int n = s.size();
        int small = 0;
        int cap = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                cap++;
            }
            else if(s[i] >= 'a' && s[i] <= 'z') {
                small++;
            }
        }
        if(small == n || cap == n) {
            return true;
        }
        else if(cap == 1 && (s[0] >= 'A' && s[0] <= 'Z') && small == n - 1) {
            return true;
        }
        return false;
    }
};