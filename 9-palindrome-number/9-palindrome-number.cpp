class Solution {
public:
    bool isPalindrome(int x) {
        long long num = x;
        long long rev_num = 0;
        if(x < 0)
            return false;
        
        while(num != 0)
        {
            int rem = num % 10;
            rev_num = rev_num * 10 + rem;
            num = num / 10;
        }
        if(x == rev_num)
            return true;
        return false;
    }
};