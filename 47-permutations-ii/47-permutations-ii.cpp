class Solution {
public:
    void helper(int ind, vector<int> &nums, vector<vector<int>> &res, vector<int> &v, int freq[]) {
        if(v.size() == nums.size()) {
            res.push_back(v);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i-1] == nums[i] && freq[i-1]) {
                continue;
            }
            if(freq[i]) {
                v.push_back(nums[i]);
                freq[i] = 0;
                helper(ind + 1, nums, res, v, freq);
                v.pop_back();
                freq[i] = 1;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int freq[nums.size()];
        for(int i = 0; i < nums.size(); i++) freq[i] = 1;
        vector<int> v;
        helper(0, nums, res, v, freq);
        return res;
    }
};