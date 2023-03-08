class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        
        for(auto it : piles) {
            high = max(high, it);
        }
        
        int ans = high;
        int n = piles.size();
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            long long cnt = 0;
            for(int i = 0; i < n; i++) {
                if(piles[i] % mid == 0) {
                    cnt += (piles[i]/mid);
                }
                else {
                    cnt += (piles[i]/mid) + 1;
                }
            }
            
            if(cnt <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};