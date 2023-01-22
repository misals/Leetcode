class Solution {
public:
    void generateAll(int ind, string &s, vector<vector<string>> &ans, vector<string> &path) {
        if(ind == s.size()) {
            ans.push_back(path);
            return;
        }
        for(int i = ind; i < s.size(); i++) {
            if(isPalindrome(ind, i, s)) {
                path.push_back(s.substr(ind, i - ind + 1));
                generateAll(i + 1, s, ans, path);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(int start, int end, string &s) {
        while(start < end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        
        generateAll(0, s, ans, path);
        return ans;
    }
};