class Solution {
public:
    int integerBreak(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        int mx = 1;
        if(n%3==0)
            return pow(3,n/3);
        else if(n%3==2)
        {
            int x = n/3;
            return 2*pow(3,x);
        }
        else
        {
            int x = n-4;
            return 4*pow(3,x/3);
        }
        return 1;
    }
};