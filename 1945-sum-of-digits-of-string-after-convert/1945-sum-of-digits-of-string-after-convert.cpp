class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            int val = s[i] - 'a' + 1;
            while(val != 0) {
                sum += val % 10;
                val /= 10;
            }
        }
        k--;
        while(k--) {
            int val = sum;
            int temp = 0;
            while(val != 0) {
                temp += val % 10;
                val /= 10;
            }
            sum = temp;
        }
        return sum;
    }
};