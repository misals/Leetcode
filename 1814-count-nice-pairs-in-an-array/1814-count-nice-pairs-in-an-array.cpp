class Solution {
public:
    int reverseDigits(int num) {
        int rev_num = 0;
        while (num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num = num / 10;
        }
        return rev_num;
    }
    
    int countNicePairs(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            int val = reverseDigits(nums[i]);
            
            v.push_back(nums[i] - val);
        }
        
        sort(v.begin(), v.end());
        
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            long long cnt = 1;
            int j = i + 1;
            
            while(j < n && v[i] == v[j]) {
                j++;
                cnt++;
            }
            
            ans = (ans + (cnt * (cnt - 1) / 2)) % mod;
            i = j - 1;
        }
        return (int)ans % mod;
    }
};