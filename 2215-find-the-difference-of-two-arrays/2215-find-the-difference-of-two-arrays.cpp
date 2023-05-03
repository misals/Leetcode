class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();
        
        map<int, int> mp1, mp2;
        
        for(int i = 0; i < n; i++) {
            mp1[nums1[i]]++;
        }
        for(int i = 0; i < m; i++) {
            mp2[nums2[i]]++;
        }
        
        vector<int> temp1, temp2;
        
        for(auto &it : mp1) {
            if(mp2.find(it.first) == mp2.end()) {
                temp1.push_back(it.first);
            }
        }
        
        for(auto &it : mp2) {
            if(mp1.find(it.first) == mp1.end()) {
                temp2.push_back(it.first);
            }
        }
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};