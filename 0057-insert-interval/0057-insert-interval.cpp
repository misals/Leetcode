class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<pair<int, int>> temp;
        
        for(auto it : intervals) {
            temp.push_back({it[0], it[1]});
        }
        temp.push_back({newInterval[0], newInterval[1]});
        
        sort(temp.begin(), temp.end());
        
        vector<vector<int>> ans;
        
        int start = temp[0].first;
        int end = temp[0].second;
        
        int n = temp.size();
        
        for(int i = 1; i < n; i++) {
            if(temp[i].first <= end) {
                end = max(end, temp[i].second);
            }
            else {
                vector<int> temp1(2);
                temp1[0] = start;
                temp1[1] = end;
                ans.push_back(temp1);
                
                start = temp[i].first;
                end = temp[i].second;
            }
        }
        vector<int> temp1(2);
        temp1[0] = start;
        temp1[1] = end;
        ans.push_back(temp1);
        
        return ans;
    }
}; 
