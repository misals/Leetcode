class Solution {
public:
    
    vector<int> countDigit(int n) {
        vector<int> ans(10);
        while(n != 0) {
            ans[n % 10]++;
            n /= 10;
        }
        return ans;
    }
    
    bool reorderedPowerOf2(int n) {
        vector<int> v = countDigit(n);
        
        int num = 1;
        for(int i = 0; i < 31; i++) {
            if(v == countDigit(num)) {
                return true;
            }
            num = num << 1;
        }
        return false;
    }
};