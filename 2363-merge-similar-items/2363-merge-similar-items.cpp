class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& item1, vector<vector<int>>& item2) {
        int n = item1.size();
        int m = item2.size();
        
        map<int, int> mp;
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            mp[item1[i][0]] += item1[i][1];
        }
        for(int i = 0; i < m; i++) {
            mp[item2[i][0]] += item2[i][1];
        }
        for(auto it : mp) {
            vector<int> temp(2);
            temp[0] = it.first;
            temp[1] = it.second;
            ans.push_back(temp);
        }
        return ans;
    }
};