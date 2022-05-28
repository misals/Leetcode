class Solution {
public:
    int n;
    void possibleStrings(int idx, string s, vector<string> &res, string str) {
        if(str.size() == s.size()) {
            res.push_back(str);
            return;
        }
        if(s[idx] >= 48 && s[idx] <= 57) {
            possibleStrings(idx + 1, s, res, str + s[idx]);
        } else {
            str.push_back(s[idx]);
            possibleStrings(idx + 1, s, res, str);
            str.pop_back();
            str.push_back(toupper(s[idx]));
            possibleStrings(idx + 1, s, res, str);
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(s[i] >= 48 && s[i] <= 57) {
                continue;
            } else if(s[i] >= 65 && s[i] <= 90 ){
                s[i] += 32;                
            }
        }
        possibleStrings(0, s, res, "");
        return res;
    }
};