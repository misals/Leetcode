class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] >= 65 && s[i] <= 90) {
                str.push_back(s[i] + 32);
            } 
            else if(s[i] >= 97 && s[i] <= 122) {
                str.push_back(s[i]);
            }
            else if(s[i] >= 48 && s[i] <= 57) {
                str.push_back(s[i]);
            }
        }
        int sz = str.size();
        for(int i = 0; i < sz/2; i++) {
            if(str[i] != str[sz-i-1]) {
                return false;
            }
        }
        return true;
    }
};