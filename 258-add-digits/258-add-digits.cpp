class Solution {
public:
    int addDigits(int num) {
        
        while(1) {
            if(num >= 0 && num <= 9) {
                return num;
            }
            int n = num;
            int sum = 0;
            while(n != 0) {
                sum += n % 10;
                n /= 10;
            }
            num = sum;
        }
    }
};