class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int ans;
        int diff = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            int low = i + 1;
            int high = n - 1;
            
            while(low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                
                if(diff > abs(sum - target)) {
                    diff = abs(sum - target);
                    ans = sum;
                }
                if(sum == target) {
                    return target;
                }
                else if(sum > target) {
                    high--;
                }
                else {
                    low++;
                }
                
            }
        }
        return ans;
    }
};