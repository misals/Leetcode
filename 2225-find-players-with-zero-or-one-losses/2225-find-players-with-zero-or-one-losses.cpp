class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lostPlayer;
        map<int, int> unique;
        vector<vector<int>> ans;
        
        int n = matches.size();
        for(int i = 0; i < n; i++) {
            unique[matches[i][0]]++;
            lostPlayer[matches[i][1]]++;
        }
        
        vector<int> temp1, temp2;
        
        for(auto it : unique) {
            if(lostPlayer.find(it.first) == lostPlayer.end()) {
                temp1.push_back(it.first);
            }
        }
        for(auto it : lostPlayer) {
            if(it.second == 1) {
                temp2.push_back(it.first);
            }
        }
        ans.push_back(temp1);
        ans.push_back(temp2);
        
        return ans;
    }
};