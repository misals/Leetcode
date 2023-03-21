class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        
        int i = 0;
        int n = nums.size();
        
        while(i < n) {
            if(nums[i] == 0) {
                long long cnt = 1;
                int j = i + 1;
                
                while(j < n && nums[j] == 0) {
                    j++;
                    cnt++;
                }
                
                if(cnt == 2) {
                    ans += 3;
                }
                else {
                    ans += (cnt * (cnt + 1)/ 2);
                }
                i = j - 1;
            }
            i++;
        }
        return ans;
    }
};