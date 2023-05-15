class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n, 0);
        vector<int> ans;
        
        int sz = queries.size();
        int cnt = 0;
        
        for(int i = 0; i < sz; i++) {
            int ind = queries[i][0];
            int val = queries[i][1];
            
            int before = 0;
            int after = 0;
            
            if(ind - 1 >= 0 && nums[ind] == nums[ind-1] && nums[ind] != 0) {
                before++;
            }
            if(ind + 1 < n && nums[ind] == nums[ind + 1] && nums[ind] != 0) {
                before++;
            }
            
            nums[ind] = val;
            
            if(ind - 1 >= 0 && nums[ind] == nums[ind-1] && nums[ind] != 0) {
                after++;
            }
            if(ind + 1 < n && nums[ind] == nums[ind + 1] && nums[ind] != 0) {
                after++;
            }
            
            cnt += (after - before);
            ans.push_back(cnt);
        }
        return ans;
    }
};