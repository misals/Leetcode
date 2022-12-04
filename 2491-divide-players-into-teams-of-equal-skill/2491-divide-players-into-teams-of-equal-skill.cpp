class Solution {
public:
    long long dividePlayers(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        int sum = arr[0] + arr[n-1];
        
        long long ans = 0;
        
        int lo = 0;
        int hi = n - 1;
        
        while(lo < hi) {
            long long tempSum = arr[lo] + arr[hi];
            if(tempSum == sum) {
                ans += (arr[lo] * arr[hi]);
            }
            else {
                return -1;
            }
            lo++;
            hi--;
        }
        return ans;
    }
};