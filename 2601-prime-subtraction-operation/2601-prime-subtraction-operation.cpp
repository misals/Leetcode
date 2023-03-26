class Solution {
public:
    void findPrimes(vector<int> &primes) {
        for(int i = 2; i <= 1000; i++) {
            bool flag = true;
            for(int j = 2; j <= i/2; j++) {
                if(i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                primes.push_back(i);
                //cout << i << " ";
            }
        }
    }
    
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> primes;
        findPrimes(primes);
        int sz = primes.size();
        
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                continue;
            }
            else {
                int j = 0;
                bool flag = false;
                while(j < sz) {
                    if(nums[i] - primes[j] < nums[i+1] && (nums[i] - primes[j]) > 0) {
                        nums[i] -= primes[j];
                        cout << nums[i] << " ";
                        flag = true;
                        break;
                    }
                    j++;
                }
                if(flag == false) return false;
                
            }
        }
        return true;
    }
};