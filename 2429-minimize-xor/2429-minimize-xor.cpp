class Solution {
public:
    
    int setKthBit(int n, int k)
    {
        return ((1 << k) | n);
    }
    
    int minimizeXor(int num1, int num2) {
        int setBits = __builtin_popcount(num2);
        
        int ans = 0;
        
        for(int i = 31; i >= 0; i--) {
            if((num1 & (1 << i)) != 0 && setBits > 0) {
                ans = setKthBit(ans, i);
                setBits--;
            }
        }
        int i = 0;
        while(setBits > 0) {
            while(i < 32) {
                if((num1 & (1 << i)) == 0 && setBits > 0) {
                    ans = setKthBit(ans, i);
                    setBits--;
                }
                i++;
            }
        }
        return ans;
    }
};