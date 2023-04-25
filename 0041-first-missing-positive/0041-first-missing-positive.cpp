class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> v;
        map<int, int> mp;
        for(auto &it : nums) {
            if(it > 0) {
                mp[it]++;
            }
        }
        for(auto &it : mp) {
            v.push_back(it.first);
        }
        sort(v.begin(), v.end());
        
        int n = v.size();
        for(int i = 0; i < n; i++) {
            if(v[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
    
};