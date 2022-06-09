class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        
        if(n == 0) {
            return 0;
        }
        
        for(int i = 0; i < n ; i++) {
            s.insert(nums[i]);
        }
        
        int ans = 1;
        for(int i = 0; i < n; i++) {
            if(s.find(nums[i] - 1) == s.end()) {
                int cnt = 1;
                int num = nums[i] + 1;
                while(s.find(num) != s.end()) {
                    num++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};