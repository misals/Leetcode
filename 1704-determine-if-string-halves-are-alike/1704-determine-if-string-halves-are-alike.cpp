class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        else if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            return true;
        }
        return false;
    }
    
    bool halvesAreAlike(string s) {
        int cnt1 = 0;
        int cnt2 = 0;
        int n = s.size();
        
        for(int i = 0; i < n/2; i++) {
            if(isVowel(s[i])) {
                cnt1++;
            }
            if(isVowel(s[i+(n/2)])) {
                cnt2++;
            }
        }
        
        return cnt1 == cnt2;
    }
};