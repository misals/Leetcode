class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> ans;
        
        int i = 0;
        int j = 0;
        
        while(i < firstList.size() && j < secondList.size()) {
            if(secondList[j][0] <= firstList[i][1] && secondList[j][1] >= firstList[i][0]) {
                vector<int> temp(2);
                temp[0] = max(secondList[j][0], firstList[i][0]);
                temp[1] = min(secondList[j][1], firstList[i][1]);
                ans.push_back(temp);
            }
            
            if(secondList[j][1] > firstList[i][1]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};