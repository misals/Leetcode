class Solution {
public:
    void helper(int ind, vector<int> &candidates, int target, vector<vector<int>> &res, int n,vector<int> vec ) {
        if(ind == n) {
            if(target == 0) {
                res.push_back(vec); 
            }
            return;
        }
        if(candidates[ind] <= target) {
            vec.push_back(candidates[ind]);
            helper(ind, candidates, target - candidates[ind], res, n, vec);
            vec.pop_back();
        } 
        helper(ind + 1, candidates, target, res, n, vec);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> vec;
        helper(0, candidates, target, res, n, vec);
        return res;
    }
};