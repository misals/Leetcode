class Solution {
public:
    int i = 0;
    void findCombinations(int val, vector<vector<int>> &res, vector<int> &vec, int k, int n) {
        if(vec.size() == k) {
            res.push_back(vec);
            return;
        }
        for(int i = val; i <= n; i++) {
            vec.push_back(i);
            findCombinations(i + 1, res, vec, k, n);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        vector<vector<int>> res;
        findCombinations(1, res, vec, k, n);
        return res;
    }
};