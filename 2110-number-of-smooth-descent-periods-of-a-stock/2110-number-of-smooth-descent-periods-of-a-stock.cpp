class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();
        int i = 0;
        
        while(i < n) {
            int j = i + 1;
            long long cnt = 1;
            
            while(j < n && (prices[j-1] == prices[j] + 1)) {
                cnt++;
                j++;
            }
            //cout << cnt << " ";
            ans += (cnt * (cnt + 1) / 2);
            
            i = j;
        }
        return ans;
    }
};