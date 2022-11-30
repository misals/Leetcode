class Solution {
public:
    int pivotInteger(int n) {
        int low = 1;
        int high = n;
        
        long long second = n * (n + 1)/2;
        
        for(int i = 1; i <= n; i++) {
            int mid = i;
            long long first = mid * (mid + 1)/2;
            mid--;
            long long temp = mid * (mid + 1)/2;
            
            if(first == (second - temp)) {
                return i;
            }
        }
        return -1;
    }
};