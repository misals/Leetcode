class Solution {
public:
    void combSum(int ind, vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i < candidates.size(); i++) {
            if(i > ind && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if(candidates[i] <= target) {
                temp.push_back(candidates[i]);
                combSum(i + 1, candidates, target - candidates[i], ans, temp);
                temp.pop_back();
            } else {
                break;
            }
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        combSum(0, candidates, target, ans, temp);
        
        return ans;
    }
};