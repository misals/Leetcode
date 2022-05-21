class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2);
        int low = 0;
        int high = numbers.size() - 1;
        
        while(low < high) {
            if((numbers[low] + numbers[high]) == target) {
                res[0] = low + 1;
                res[1] = high + 1;
                break;
            } else if((numbers[low] + numbers[high]) > target) {
                high--;
            } else {
                low++;
            }
        }
        return res;
    }
};