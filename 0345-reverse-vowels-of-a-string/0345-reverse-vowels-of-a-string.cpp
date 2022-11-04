class Solution {
public:
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
            if(check(s[low]) && check(s[high])) {
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