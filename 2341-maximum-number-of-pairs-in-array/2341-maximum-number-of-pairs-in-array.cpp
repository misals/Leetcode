class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v(2);
        int n = nums.size();
        
        if(n == 1) {
            v[1]++;
            return v;
        }
        
        for(int i = 0; i < n; i++) {
            if(i + 1 < n && nums[i] == nums[i+1]) {
                v[0]++;
                i++;
            }
            else {
                v[1]++;
            }
        }
        return v;
    }
};