class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(i == 0 || (nums[i] != nums[i-1])) {
                int sum = 0 - nums[i];
                
                int lo = i + 1;
                int hi = n - 1;
                
                while(lo < hi) {
                    if(nums[lo] + nums[hi] == sum) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        res.push_back(temp);
                        
                        while(lo < hi && nums[lo] == nums[lo + 1]) {
                            lo++;
                        }
                        
                        while(lo < hi && nums[hi] == nums[hi - 1]) {
                            hi--;
                        }
                        lo++;
                        hi--;
                    } else if(nums[lo] + nums[hi] < sum) {
                        lo++;
                    } else {
                        hi--;
                    }
                }
            }
        }
        return res;
    }
};