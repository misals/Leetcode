class Solution {
public:
    bool check(char a, char b) {
        bool flag1 = false;
        bool flag2 = false;
        if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
            flag1 = true;
        }
        if(b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u') {
            flag2 = true;
        }
        
        if(a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U') {
            flag1 = true;
        }
        if(b == 'A' || b == 'E' || b == 'I' || b == 'O' || b == 'U') {
            flag2 = true;
        }
        
        if(flag1 && flag2)
            return true;
        return false;
    }
    
    bool check(char a) {
        bool flag1 = false;
        if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
            flag1 = true;
        }
        if(a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U') {
            flag1 = true;
        }
        return flag1;
    }
    
    string reverseVowels(string s) {
        int low = 0;
        int high = s.size() - 1;
        
        while(low < high) {
            if(check(s[low], s[high])) {
                swap(s[low], s[high]);
                low++;
                high--;
            }
            else if(check(s[low])) {
                high--;
            }
            else if(check(s[high])) {
                low++;
            }
            else {
                low++;
                high--;
            }
        }
        return s;
    }
};