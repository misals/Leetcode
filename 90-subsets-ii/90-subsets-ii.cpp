class Solution {
public:
    void generateSubset(int ind, vector<vector<int>> &ans, vector<int>& nums, vector<int> &temp) {
        ans.push_back(temp);
        for(int i = ind; i < nums.size(); i++) {
            if(i != ind && nums[i] == nums[i-1]) {
                continue;
            }
            temp.push_back(nums[i]);
            generateSubset(i+1, ans, nums, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        generateSubset(0, ans, nums, temp);
        return ans;
    }
};