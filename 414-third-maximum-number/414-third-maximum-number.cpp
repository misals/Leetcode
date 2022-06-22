class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LONG_MIN;
        long long second = LONG_MIN;
        long long third = LONG_MIN;
        
        for(auto it : nums) {
            if(it > first) {
                third = second;
                second = first;
                first = it;
            } else if(it > second && it < first) {
                third = second;
                second = it;
            } else if(it > third && it < second) {
                third = it;
            }
        }
        return third == LONG_MIN ? first : third;
    }
};