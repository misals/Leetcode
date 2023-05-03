class Solution {
public:
    int isWinner(vector<int>& a, vector<int>& b) {
        int sum1 = 0;
        int sum2 = 0;
        
        int n = a.size();
        
        for(int i = 0; i < n; i++) {
            if(i >= 1 && a[i-1] == 10) {
                sum1 += a[i] * 2;
            }
            else if(i >= 2 && a[i-2] == 10) {
                sum1 += a[i] * 2;
            }
            else {
                sum1 += a[i];
            }
            
            if(i >= 1 && b[i-1] == 10) {
                sum2 += b[i] * 2;
            }
            else if(i >= 2 && b[i-2] == 10) {
                sum2 += b[i] * 2;
            }
            else {
                sum2 += b[i];
            }
        }
        if(sum1 > sum2) {
            return 1;
        }
        if(sum2 > sum1) {
            return 2;
        }
        return 0;
    }
};