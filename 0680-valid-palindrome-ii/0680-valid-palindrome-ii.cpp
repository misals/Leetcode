class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while(i <= j) {
            if(s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int lo = 0;
        int hi = s.size() - 1;
        
        while(lo <= hi) {
            if(s[lo] == s[hi]) {
                lo++;
                hi--;
            }
            else {
                if(isPalindrome(lo + 1, hi, s) || isPalindrome(lo, hi - 1, s)) {
                    return true;
                }
                return false;
            }
        }
        return true;
    }
};