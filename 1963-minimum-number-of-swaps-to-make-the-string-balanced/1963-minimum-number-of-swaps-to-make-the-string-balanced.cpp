class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int lo = 0;
        int hi = n - 1;
        
        int swaps = 0, cnt = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '[') {
                cnt++;
            }
            else {
                cnt--;
            }
            if(cnt < 0) {
                swaps++;
                while(hi > i && s[hi] == ']') {
                    hi--;
                }
                cnt = 1;
            }
        }
        return swaps;
        
    }
};