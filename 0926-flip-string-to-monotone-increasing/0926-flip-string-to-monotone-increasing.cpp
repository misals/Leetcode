class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0;
        int cnt = 0;
        
        for(auto ch : s) {
            if(ch == '0') {
                ans = min(cnt, ans + 1);
            }
            else {
                cnt++;
            }
        }
        return ans;
    }
};