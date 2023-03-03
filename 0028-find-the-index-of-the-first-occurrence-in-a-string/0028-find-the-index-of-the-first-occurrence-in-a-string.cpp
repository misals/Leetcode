class Solution {
public:
    int strStr(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        int i = 0;
        
        while(i < n) {
            int j = 0;
            int cnt = 0;
            int ind = i;
            
            while(j < m) {
                if(s[ind] == t[j]) {
                    ind++;
                    j++;
                    cnt++;
                }
                else {
                    break;
                }
            }
            if(cnt == m) {
                return i;
            }
            else {
                i++;
            }
        }
        return -1;
    }
};