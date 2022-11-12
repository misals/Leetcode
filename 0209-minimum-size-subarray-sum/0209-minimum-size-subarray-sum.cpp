class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int low = 0;
        int high = 0;
        int mini = INT_MAX;
        int n = arr.size();
        
        int sum = 0;
        while(high < n) {
            sum += arr[high];
            if(sum >= target) {
                mini = min(mini, high - low + 1);
                while(sum >= target) {
                    sum -= arr[low];
                    low++;
                }
                mini = min(mini, high - low + 2);
            }
            high++;
          }
          if(mini == INT_MAX) {
            return 0;
          }
          return mini;
    }
};