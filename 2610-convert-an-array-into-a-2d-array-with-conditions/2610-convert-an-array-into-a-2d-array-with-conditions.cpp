class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        vector<vector<int>> ans;
        
        while(mp.size() >= 1) {
            vector<int> temp;
            
            for(auto &it : mp) {
                if(it.second >= 1) {
                    temp.push_back(it.first);
                    it.second--;
                }
            }
            for(auto &it : mp) {
                if(it.second == 0) {
                    mp.erase(it.first);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};