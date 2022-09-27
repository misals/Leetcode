class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            int end = i;
            
            while(end < n && s[i] == s[end]) {
                end++;
            }
            int val = end - i;
            if(val >= 3) {
                vector<int> temp(2);
                temp[0] = i;
                temp[1] = end - 1;
                ans.push_back(temp);
            }
            i = end - 1;
        }
        return ans;
    }
};