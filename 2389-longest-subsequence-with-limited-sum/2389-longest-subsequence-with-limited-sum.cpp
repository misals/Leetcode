class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = queries.size();
        
        vector<int> ans(m);
        
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            int sum = 0;
            for(int j = 0; j < n; j++) {
                if(sum + nums[j] <= queries[i]) {
                    cnt++;
                    sum += nums[j];
                }
                else {
                    break;
                }
            }
            ans[i] = cnt;
        }
        return ans;
    }
};