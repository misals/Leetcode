class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        map<int, vector<int>> mp;
        
        int n = score.size();
        int m = score[0].size();
        
        for(int i = 0; i < n; i++) {
            mp[score[i][k]] = score[i];
        }
        vector<vector<int>> ans;
        
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};