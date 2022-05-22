class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int m = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            int sz = strs[i].size();
            m = min(m, sz);
        }
        
        string res = "";
        for(int i = 0; i < m; i++) {
            char ch = strs[0][i];
            for(int j = 1; j < n; j++) {
                if(ch != strs[j][i]) {
                    return res;
                }
            }
            res.push_back(ch);
        }
        return res;
    }
};