class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        int carry = 0;
        bool flag = true;
        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] == 9 && flag) {
                ans.push_back(0);
                carry = 1;
            }
            else if(flag) {
                digits[i]++;
                carry = 0;
                ans.push_back(digits[i]);
                flag = false;
            }
            else {
                ans.push_back(digits[i]);
            }
        }
        if(carry) {
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};