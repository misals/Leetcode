class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }
            else {
                vector<int> temp(2);
                temp[0] = start, temp[1] = end;
                ans.push_back(temp);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> temp(2);
        temp[0] = start, temp[1] = end;
        ans.push_back(temp);
        return ans;
    }
};