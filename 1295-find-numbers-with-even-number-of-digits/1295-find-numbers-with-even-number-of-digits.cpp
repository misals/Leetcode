class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto it : nums) {
            int cnt = 0;
            while(it != 0) {
                cnt++;
                it /= 10;
            }
            if(cnt % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};