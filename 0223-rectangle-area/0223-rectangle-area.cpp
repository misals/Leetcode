class Solution {
public:
    int computeArea(int a, int b, int c, int d, int a1, int b1, int c1, int d1) {
        int val1 = (c - a) * (d - b);
        int val2 = (c1 - a1) * (d1 - b1);
        
        int num1 = max(min(c, c1) - max(a, a1), 0);
        int num2 = max(min(d, d1) - max(b, b1), 0);
        
        return val1 + val2 - (num1 * num2);
    }
};