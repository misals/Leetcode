class Solution {
public:
    
    void helper(int ind, vector<int> &nums, vector<vector<int>> &res, vector<int> &v, int n) {
        res.push_back(v);
        for(int i = ind; i < n; i++) {
            if(i != ind && nums[i] == nums[i-1]) {
                continue;
            }
            v.push_back(nums[i]);
            helper(i + 1, nums, res, v, n);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> v;
        sort(nums.begin(),nums.end());
        helper(0, nums, res, v, n);
        return res;
    }
};