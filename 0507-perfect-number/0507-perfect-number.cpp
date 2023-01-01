class Solution {
public:
    bool checkPerfectNumber(int num) {
        long long sum = 0;
        
        int val = num;
        
        for(int i = 1; i <= (num+1)/2; i++) {
            if(i != val && val % i == 0) {
                sum += i;
            }
        }
        return sum == num;
    }
};