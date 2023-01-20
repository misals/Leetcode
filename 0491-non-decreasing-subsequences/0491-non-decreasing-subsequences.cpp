class Solution {
public:
    void solve(int ind, int n, vector<int> &temp, map<vector<int>, int> &ans, vector<int> &nums) {
        if(ind >= n) {
            if(temp.size() >= 2) {
                ans[temp] = 1;
            }
            return;
        }
        
        solve(ind + 1, n, temp, ans, nums);
        if(temp.size() >= 1) {
            int sz = temp.size();
            if(nums[ind] >= temp[sz-1]) {
                temp.push_back(nums[ind]);
                solve(ind + 1, n, temp, ans, nums);
                temp.pop_back();
            }
        }
        else {
            temp.push_back(nums[ind]);
            solve(ind + 1, n, temp, ans, nums);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        map<vector<int>, int> ans;
        vector<int> temp;
        
        solve(0, n, temp, ans, nums);
        
        vector<vector<int>> res;
        for(auto it : ans) {
            res.push_back(it.first);
        }
        return res;
    }
};