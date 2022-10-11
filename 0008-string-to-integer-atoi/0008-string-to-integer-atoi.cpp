class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        bool neg = false;
        long long int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                
            }
            else {
                if(s[i] == '-') {
                    neg = true;
                    i++;
                }
                else if(s[i] == '+') {
                    i++;
                }
                while(i < n && s[i] >= '0' && s[i] <= '9') {
                    ans = ans * 10 + (s[i] - '0');
                    if(ans > INT_MAX) {
                        break;
                    }
                    i++;
                }
                break;
            }
        }
        if(neg) {
            ans *= -1;
        }
        if(ans < INT_MIN) return INT_MIN;
        if(ans > INT_MAX) return INT_MAX;
        
        return (int)ans;
    }
};