class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while(l <= r) {
            if(s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    
    void palindromePartition(int ind, string &s, vector<vector<string>> &res, vector<string> &str) {
        if(ind == s.size()) {
            res.push_back(str);
            return;
        }
        for(int i = ind; i < s.size(); i++) {
            if(isPalindrome(s, ind, i)) {
                str.push_back(s.substr(ind, i - ind + 1));
                palindromePartition(i + 1, s, res, str);
                str.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> str;
        palindromePartition(0, s, res, str);
        return res;
    }
};