class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        long long val = 0;
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            if((val*10 + (s[i] - '0')) <= k) {
                val *= 10;
                val += (s[i] - '0');
            }
            else {
                if((s[i] - '0') > k) {
                    return -1;
                }
                cnt++;
                val = (s[i] - '0');
            }
        }
        if(val > 0) cnt++;
        return cnt;
    }
};