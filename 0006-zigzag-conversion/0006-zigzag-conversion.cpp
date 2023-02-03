class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows, "");
        int n = s.size();
        int i = 0;
        
        while(i < n) {
            for(int j = 0; j < numRows && i < n; j++) {
                v[j].push_back(s[i++]);
            }
            for(int j = numRows - 2; j >= 1&& i < n; j--) {
                v[j].push_back(s[i++]);
            }
        }
        string ans = "";
        for(auto it : v) {
            ans += it;
        }
        return ans;
    }
};