class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int start = arr[0][0];
        int end = arr[0][1];
        int cnt = 1;
        
        for(int i = 1; i < n; i++) {
            if(arr[i][0] >= start && arr[i][0] <= end) {
                start = max(start, arr[i][0]);
                end = min(end, arr[i][1]);
            }
            else {
                cnt++;
                start = arr[i][0];
                end = arr[i][1];
            }
        }
        
        return cnt;
    }
};