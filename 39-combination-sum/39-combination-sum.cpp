class Solution {
public:
    void uniqueComb(int ind, vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp) {
        if(ind == candidates.size()) {
            if(target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if(target - candidates[ind] >= 0) {
            target -= candidates[ind];
            temp.push_back(candidates[ind]);
            uniqueComb(ind, candidates, target, ans, temp);
            temp.pop_back();
            target += candidates[ind];
        }
        uniqueComb(ind + 1, candidates, target, ans, temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        uniqueComb(0, candidates, target, ans, temp);
        
        return ans;
        
    }
};