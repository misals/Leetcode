class Solution {
public:
    bool isVowel(string &s) {
        int n = s.size();
        if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') {
            if(s[n - 1] == 'a' || s[n - 1] == 'e' || s[n - 1] == 'i' || s[n - 1] == 'o' || s[n - 1] == 'u') {
                return true;
            }
        }
        return false;
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        
        vector<int> prefix(n + 2, 0);
        
        for(int i = 0; i < n; i++) {
            if(isVowel(words[i])) {
                prefix[i + 1] = prefix[i] + 1;
            }
            else {
                prefix[i + 1] = prefix[i];
            }
        }
        
        vector<int> ans;
        for(auto it : queries) {
            int l = it[0] + 1;
            int r = it[1] + 1;
            
            ans.push_back(prefix[r] - prefix[l-1]);
        }
        return ans;
    }
};