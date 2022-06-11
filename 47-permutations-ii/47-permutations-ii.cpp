class Solution {
public:
    void generateAll(int ind, vector<int> nums, vector<vector<int>> &ans) {
        if(ind == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        for(int i = ind; i < nums.size(); i++) {
            if(i != ind && nums[i] == nums[ind]) {
                continue;
            } 
            swap(nums[ind], nums[i]);
            generateAll(ind + 1, nums, ans);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        generateAll(0, nums, ans);
        
        return ans;
    }
};