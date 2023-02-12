class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        
        int low = 0;
        int high = n - 1;
        
        while(low <= high) {
            if(low == high) {
                ans += nums[low];
                break;
            }
            else {
                string temp1 = to_string(nums[low]);
                string temp2 = to_string(nums[high]);
                string temp = temp1 + temp2;
                
                int val = stoi(temp);
                
                ans += val;
                low++;
                high--;
            }
        }
        return ans;
    }
};