class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1) return true;
        
        long long x = 3;
        
        while(x < n) {
            x *= 3;
        }
        return x == n;
    }
};