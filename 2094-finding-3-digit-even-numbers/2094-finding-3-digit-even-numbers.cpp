class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {
        int n = nums.size();
        set<int> ans;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                for(int j = 0; j < n; j++) {
                    if(i != j) {
                        for(int k = 0; k < n; k++) {
                            if(i != k && j != k) {
                                int val = nums[i];
                                val = val * 10 + nums[j];
                                val = val * 10 + nums[k];

                                if(val % 2 == 0) {
                                    ans.insert(val);
                                }
                            }
                        }
                    }
                }
            }
        }
        vector<int> res(ans.begin(), ans.end());
        return res;
    }
};