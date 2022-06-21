class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        bool flag = false;
        while(1) {
            int num = 0;
            while(n != 0) {
                int rem = n % 10;
                num += (rem*rem);
                n /= 10;
            }
            if(num == 1) {
                flag = true;
                break;
            } else if(s.find(num) != s.end()) {
                break;
            } else {
                s.insert(num);
                n = num;
            }
        }
        if(flag) {
            return true;
        }
        return flag;
    }
};