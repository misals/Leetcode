class Solution {
public:
    void helper(vector<int> &nums, vector<vector<int>> &res, vector<int> &v, int freq[])
    {
        if(v.size() == nums.size()) {
            res.push_back(v);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!freq[i]){
                freq[i] = 1;
                v.push_back(nums[i]);
                helper(nums, res, v, freq);
                freq[i] = 0;
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        int n = nums.size();
        int freq[n];
        for(int i = 0; i < n; i++) freq[i] = 0;
        helper(nums, res, v, freq);
        return res;
    }
};