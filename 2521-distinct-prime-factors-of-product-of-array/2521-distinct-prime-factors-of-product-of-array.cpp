class Solution {
public:
    void findPrime(vector<int> &v) {
        for(int i = 2; i <= 1000; i++) {
            bool flag = true;
            for(int j = 2; j <= (i+1)/2; j++) {
                if(i % j == 0) {
                    flag = false;
                }
            }
            if(flag) {
                v.push_back(i);
            }
        }
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> v;
        findPrime(v);
        
        int n = nums.size();
        int sz = v.size();
        set<int> s;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < sz; j++) {
                if(nums[i] % v[j] == 0) {
                    s.insert(v[j]);
                    
                }
            }
        }
        return s.size();
    }
};