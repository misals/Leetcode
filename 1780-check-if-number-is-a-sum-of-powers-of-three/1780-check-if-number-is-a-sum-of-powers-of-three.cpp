class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<long long> v;
        for(int i = 0; i <= 25; i++) {
            v.push_back(pow(3, i));
        }
        
        for(int i = 25; i >= 0; i--) {
            if(n >= v[i]) {
                n -= v[i];
            }
            if(n == 0) break;
        }
        return n == 0;
    }
};