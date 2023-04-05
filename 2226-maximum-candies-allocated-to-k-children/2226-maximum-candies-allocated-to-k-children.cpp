class Solution {
public:
    bool isPossible(int mid, long long k, vector<int> &nums) {
        
        int n = nums.size();
        long long cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += (nums[i] / mid);
        }
        if(cnt >= k) {
            return true;
        }
        return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        
        for(auto &it : candies) {
            sum += it;
        }
        if(sum < k) return false;
        
        int ans = 0;
        int low = 1;
        int high = 1e9;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(isPossible(mid, k, candies)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};