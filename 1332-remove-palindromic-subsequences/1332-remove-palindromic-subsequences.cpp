class Solution {
public:
    int removePalindromeSub(string s) {
        int low = 0;
        int high = s.size() - 1;
        
        while(low <= high) {
            if(s[low++] != s[high--]) {
                return 2;
            }
        }
        return 1;
    }
};