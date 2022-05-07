class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int sum = 0;
        while(1) {
            sum = 0;
            while(n != 0) {
                sum += (n % 10) * (n % 10);
                n = n /10;
            }
            if(sum == 1) {
                return true;
            }
            else if(s.find(sum) != s.end()) {
                return false;
            } 
            s.insert(sum);
            n = sum;
        }
        return true;
    }
};