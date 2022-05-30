class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) {
            return 1;
        }
        bool checkSign = (dividend < 0 == divisor < 0);
        unsigned int num1 = abs(dividend);
        unsigned int num2 = abs(divisor);
        
        unsigned int ans = 0;
        
        while(num1 >= num2) {
            int i = 0;
            while(num1 > (num2 << (i + 1))) {
                i++;
            }
            ans += (1 << i);
            num1 -= (num2 << i);
        }
        
        if(ans == (1 << 31) && checkSign) {
            return INT_MAX;
        }
        
        return checkSign ? ans : -ans;
    }
};