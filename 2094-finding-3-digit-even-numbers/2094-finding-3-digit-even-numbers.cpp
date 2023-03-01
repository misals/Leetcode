class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(10, 0);
        
        for(int i = 0; i < n; i++) {
            count[nums[i]]++;
        }
        vector<int> ans;
        
        for(int i = 100; i <= 999; i++) {
            int val = i;
            
            vector<int> tempCnt(10, 0);
            
            while(val != 0) {
                tempCnt[val % 10]++;
                val /= 10;
            }
            bool flag = true;
            
            for(int i = 0; i < 10; i++) {
                if(count[i] < tempCnt[i]) {
                    flag = false;
                }
            }
            
            if(flag && i % 2 == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};