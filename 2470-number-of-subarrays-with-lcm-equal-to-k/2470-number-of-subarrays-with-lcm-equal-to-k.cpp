class Solution {
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    int subarrayLCM(vector<int>& arr, int k) {
        int ans = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            long long lcm = arr[i];
            for(int j = i; j < n; j++) {
                lcm = (((arr[j] * lcm)) / (gcd(arr[j], lcm)));
                if(lcm == k) {
                    ans++;
                }
                else if(lcm > k) {
                    break;
                }
            }
        }
        return ans;
    }
};