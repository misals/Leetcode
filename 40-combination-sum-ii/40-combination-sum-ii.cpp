class Solution {
public:
    void helper(int ind, vector<int> &candidates, int target, vector<vector<int>> &res, int n, vector<int> &v) {
        if(target == 0) {
            res.push_back(v);
            return;
        }
        for(int i = ind; i < n; i++)
        {
            if(i > ind && candidates[i] == candidates[i-1]) {
                continue;
            }
            if(candidates[i] > target) {
                break;
            }
            v.push_back(candidates[i]);
            helper(i + 1, candidates, target - candidates[i], res, n, v);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        helper(0, candidates, target, res, n, v);
        return res;
    }
};