class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n == 1) return true;
        
        long long x = 4;
        
        while(x < n) {
            x *= 4;
        }
        return x == n;
    }
};