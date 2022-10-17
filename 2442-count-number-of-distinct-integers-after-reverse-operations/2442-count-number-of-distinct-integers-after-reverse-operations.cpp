class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        set<int> s;
        for(auto it : nums) {
            s.insert(it);
        }
        for(auto it : nums) {
            int num = it;
            long long revNum = 0;
            while(num != 0) {
                revNum = revNum * 10 + num % 10;
                num /= 10;
            }
            s.insert(revNum);
            
        }
        return s.size();
    }
};