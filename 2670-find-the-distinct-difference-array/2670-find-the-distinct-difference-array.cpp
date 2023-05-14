class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            map<int, int> l, r;
            
            for(int j = 0; j <= i; j++) {
                l[nums[j]]++;
            }
            for(int j = i + 1; j < n; j++) {
                r[nums[j]]++;
            }
            
            int val1 = l.size();
            int val2 = r.size();
            
            ans.push_back(val1 - val2);
        }
        return ans;
    }
};