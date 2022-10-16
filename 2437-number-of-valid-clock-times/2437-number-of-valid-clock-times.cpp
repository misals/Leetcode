class Solution {
public:
    int countTime(string s) {
        int ans = 0;
        if(s[0] == '?') {
            if(s[1] == '?') {
                ans += 24;
            }
            else if(s[1] >= '0' && s[1] <= '3') {
                ans += 3;
            }
            else {
                ans += 2;
            }
        }
        else {
            if(s[1] == '?') {
                if(s[0] == '0' || s[0] == '1') {
                    ans += 10;
                }
                else {
                    ans += 4;
                }
            }
        }
        
        int ans2 = 0;
        
        if(s[3] == '?') {
            if(s[4] == '?') {
                ans2 += 60;
            }
            else {
                ans2 += 6;
            }
        }
        else {
            if(s[4] == '?') {
                ans2 += 10;
            }
        }
        if(ans != 0 && ans2 != 0) {
            return ans * ans2;
        }
        else if(ans != 0) {
            return ans;
        }
        else if(ans2 != 0) {
            return ans2;
        }
        return 1;
    }
};