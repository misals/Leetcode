class Solution {
public:
    void generateSubset(int ind, vector<int> &temp, vector<int>& nums, vector<vector<int>> &ans) {
        if(ind == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        generateSubset(ind + 1, temp, nums, ans);
        temp.pop_back();
        generateSubset(ind + 1, temp, nums, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        generateSubset(0, temp, nums, ans);
        return ans;
    }
};