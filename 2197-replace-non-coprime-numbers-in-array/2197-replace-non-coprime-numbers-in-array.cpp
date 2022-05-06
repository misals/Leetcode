class Solution {
public:
    
    long long __gcd(long long x, long long y)
    {
        if(y == 0)
            return x;
        return __gcd(y, x % y);
    }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        int n = nums.size();
        
        for(int i = 1; i < n; i++)
        {
            long long y = nums[i];
            while(ans.size() > 0 && __gcd(y, ans.back()) > 1)
            {
                long long x = ans.back();
                ans.pop_back();
                y = (x * y) / __gcd(x,y);
            }
            ans.push_back(y);
        }
        return ans;
    }
};