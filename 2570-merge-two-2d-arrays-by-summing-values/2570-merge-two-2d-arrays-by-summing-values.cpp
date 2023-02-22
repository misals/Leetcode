class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mp;
        
        for(auto it : nums1) {
            mp[it[0]] = it[1]; 
        }
        
        for(auto it : nums2) {
            mp[it[0]] += it[1];
        }
        
        vector<vector<int>> ans;
        
        for(auto it : mp) {
            vector<int> temp(2);
            temp[0] = it.first;
            temp[1] = it.second;
            ans.push_back(temp);
        }
        
        return ans;
    }
};