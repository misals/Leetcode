class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> ans;
        
        int i = n - 1;
        
        int carry = 0;
        while(k != 0 && i >= 0) {
            int rem = k % 10;
            if(num[i] + rem + carry <= 9) {
                ans.push_back(num[i] + rem + carry);
                carry = 0;
            }        
            else {
                ans.push_back((num[i] + rem + carry) % 10);
                carry = 1;
            }
            k /= 10;
            i--;
        }
        while(k == 0 && i >= 0) {
             if(num[i] + carry <= 9) {
                ans.push_back(num[i] + carry);
                carry = 0;
            }        
            else {
                ans.push_back((num[i] + carry) % 10);
                carry = 1;
            }
            i--;
        }
        
        while(i < 0 && k != 0) {
            int rem = k % 10;
            if(rem + carry <= 9) {
                ans.push_back(rem + carry);
                carry = 0;
            }        
            else {
                ans.push_back((rem + carry) % 10);
                carry = 1;
            }
            k /= 10;
        }
        if(k == 0 && i < 0 && carry == 1) {
            ans.push_back(1);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};