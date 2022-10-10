class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        if(n == 1) {
            return "";
        }
        
        int pos = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] != 'a') {
                pos = i;
                break;
            }
        }
        if(pos == -1) {
            s[n - 1] = 'b';
        }
        else if(n % 2 == 0 && pos == ((n / 2) - 1)) {
            s[n/2 - 1] = 'a';
        }
        else if(n % 2 != 0 && pos == n / 2) {
            s[n - 1] = 'b';
        }
        else {
            s[pos] = 'a';
        }
        return s;
        
    }
};