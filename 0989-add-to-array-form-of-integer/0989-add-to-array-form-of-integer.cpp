class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int carry = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            int val = nums[i] + (k % 10) + carry;
            ans.push_back(val % 10);
            carry = val / 10;
            k /= 10;
        }
        while(k != 0) {
            int val = k % 10;
            val += carry;
            ans.push_back(val % 10);
            carry = val / 10;
            k /= 10;
        }
        if(carry) {
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};